#include<bits/stdc++.h>
using namespace std;
int n,m,ma,ms,mx,nm=(1<<21)-1,a[200007];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(a[i],ma);
        nm=nm&a[i];
    }
    if(m==1){
        cout<<ma;
        return 0;
    }
    if(m==n){
        cout<<nm;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ms=max(ms,a[i]&a[j]);
            }
        }
        return 0;
    }
    if(n<=20){
        for(int i=1;i<=(1<<n)-1;i++){
            int t=i,x=(1<<21)-1,q=0;
            for(int j=1;j<=n;j++){
                if(t&1==1){
                    x=x&a[j];
                    q++;
                }
                t=t>>1;
            }
            if(q==m){
                mx=max(mx,x);
            }
        }
        cout<<mx;
        return 0;
    }
    return 0;
}
