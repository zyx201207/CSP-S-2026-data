#include<bits/stdc++.h>
using namespace std;
long long n,m,oo=1,ans,a[500009],b[500009];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       cin>>a[i];
        if(i>=3){
            if(a[i]-a[i-1]!=a[i-1]-a[i-2])oo=0;
        }
    }
    sort(a+1,a+1+n);
    if(oo){
        if(a[2]-a[1]==0){
            cout<<n;
        }
        else{
            m/=(a[2]-a[1]);
            if((int)(sqrt(m*2))*((int)(sqrt(m*2)+1))>m*2){
                cout<<(int)(sqrt(m*2)-1);
            }
            else cout<<(int)(sqrt(m*2));
        }
    }
    else{
        for(int i=1;i<=n;i++){
            long long k=0,t=i;
            while(k+a[t]*t<=m&&t<n){
                k+=a[t]*t;
                t++;
            }
            ans=max(ans,t-i+1);
        }
        cout<<ans;
    }
    return 0;
}
