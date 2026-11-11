#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
ull n,m,a[500010],fa[500010],ans=1;
bool f=true;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ull x=a[2]-a[1];
    for(int i=1;i<n;i++){
        fa[i]=a[i+1]-a[i];
        if(fa[i]!=x)f=false;
    }
    if(f){
        ull dq=1;
        while(m>0){
            if(m>=x*dq){
                m-=x*dq;
                ans++;
            }
            dq++;
            if(m<x*dq)break;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        ull y=a[i+1]-a[i];
        if(m>=i*y){
            m-=i*y;
            ans++;
        }
        else break;
    }
    cout<<ans;
    return 0;
}
