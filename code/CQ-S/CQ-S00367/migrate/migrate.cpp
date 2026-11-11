#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,d,res;
ll x[2000001],r[2000001];
ll f[2000001][3];
void solve() {
    res=0;
    cin>>n>>d;
    for(ll i=1;i<=n;i++)
        cin>>x[i],r[i]=i;
    for(ll i=1;i<=n;i++) 
        f[i][0]=f[i][1]=f[i][2]=0;
    for(ll i=1;i<=n;i++) {
        r[i]=max(r[i],r[i-1]);
        while(r[i]<n)
            if(x[r[i]+1]-x[i]<=d)
                r[i]++;
            else break;
    }
    for(ll i=1;i<n;i++) {
        ll lst=res;
        ll el=i,er=r[i-1];
        if(i>=3) {
            if(i>2)
                el=max(el,r[i-2]);
            res+=f[i][1]*max(er-el,0ll);
        }
        el=i,er=r[i];
        if(i>=4) {
            if(i>1)
                el=max(el,r[i-1]);
            res+=f[i][2]*max(er-el,0ll);
        }
        if(r[i]!=r[i-1]||i==1) 
            f[r[i]][0]+=f[i][0];
        if(r[i]-i>1&&(r[i-1]<r[i]-1||i==1))
            f[r[i]][1]+=f[i][0];
        if(i>=3)
            if(r[i-1]==r[i]&&r[i-2]!=r[i])
                f[r[i]][2]+=f[i][1];
        if(i>=4)
            if(r[i-1]!=r[i])
                f[r[i]][2]+=f[i][2];
        f[r[i]][0]++;
        if(r[i]-i>1)
            f[r[i]][1]++;
    }
    cout<<res<<'\n';
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    ll c,T;
    cin>>c>>T;
    while(T--)
        solve();    
    return 0;
}