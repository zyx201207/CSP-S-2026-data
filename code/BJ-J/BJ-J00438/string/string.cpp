#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,str[200005]={0};
    long long cnt=0,l[200005]={0};
    cin>>n;
    int cmp1=0,cmp2=n-1;
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        l[i]=a;
        str[i]=c;
    }
    while(cmp1<cmp2){
        if(str[cmp1]!=str[cmp2]){
            if(l[cmp1]>l[cmp2]){
                cnt+=l[cmp2];
                l[cmp1]-=l[cmp2];
                cmp2--;
            }
            else if(l[cmp2]>l[cmp1]){
                cnt+=l[cmp1];
                l[cmp2]-=l[cmp1];
                cmp1++;
            }
            else{
                cnt+=l[cmp1];
                cmp1++;cmp2--;
            }
        }
        else{
            if(l[cmp1]>l[cmp2]){
                l[cmp1]-=l[cmp2];
                cmp2--;
            }
            else if(l[cmp2]>l[cmp1]){
                l[cmp2]-=l[cmp1];
                cmp1++;
            }
            else{
                cmp1++;cmp2--;
            }
        }
    }
    cout<<cnt;
    return 0;
}
