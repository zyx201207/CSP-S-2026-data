#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],zm[200005],s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>a[i]>>c;
        zm[i]=c-'a'+1;
    }
    for(int i=1,j=n;i<j;){
        if(zm[i]==zm[j]){
            if(a[j]>a[i]){
                a[j]-=a[i];
                a[i]=0;
                i++;
            }else if(a[j]==a[i]){
                a[j]=0;
                j--;
                a[i]=0;
                i++;
            }else{
                a[i]-=a[j];
                a[j]=0;
                j--;
            }
        }else{
            if(a[j]>a[i]){
                a[j]-=a[i];
                s+=a[i];
                a[i]=0;
                i++;
            }else if(a[j]==a[i]){
                s+=a[i];
                a[j]=0;
                j--;
                a[i]=0;
                i++;
            }else{
                a[i]-=a[j];
                s+=a[j];
                a[j]=0;
                j--;
            }
        }
    }
    cout<<s;
    return 0;
}
