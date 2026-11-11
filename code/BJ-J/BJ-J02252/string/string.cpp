#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[100010],t=0,ans;
    string a[100010];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }for(int i=1;i<=n;i++){
        if(b[i]==b[1]){
            cout<<0;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=a[n+1-i]||b[i]!=b[n+1-i]){
            if(a[i]>=a[n+1-i]){
                ans+=a[i];
                a[n-i]=a[n-i]-a[i]+a[n+1-i];
            }else{
                ans+=a[n+1-i];
                a[i+1]=a[i+1]+a[i]-a[n+1-i];
            }
        }
    }
    cout<<ans;
    return 0;
}

