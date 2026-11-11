#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[10001][2]={};
    for(int i=1;i<=n;i++){
        int a1;
        char b;
        cin>>a1>>b;
        a[i][0]=a1;
        a[i][1]=b-'a'+1;
    }
    int t=1,w=n;
    int ans=0;
    while(t<w){
        int mn;
        if(a[t][1]==a[w][1]){
            if(a[t][0]>a[w][0]){
                a[t][0]-=a[w][0];
                w--;
            }else if(a[t][0]<a[w][0]){
                a[w][0]-=a[t][0];
                t++;
            }else{
                t++;
                w--;
            }
        }else{
            if(a[t][0]>a[w][0]){
                a[t][0]-=a[w][0];
                ans+=a[w][0];
                w--;
            }else if(a[t][0]<a[w][0]){
                a[w][0]-=a[t][0];
                ans+=a[t][0];
                t++;
            }else{
                ans+=a[t][0];
                ans+=a[w][0];
                t++;
                w--;

            }
        }
    }
    cout<<ans;
    return 0;
}
