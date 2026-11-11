#include<bits/stdc++.h>
#define ll long long
#define MAXN 2000005
#define inf 0x3f3f3f3f
using namespace std;
ll n,m,dp[MAXN],a[MAXN],C,f[MAXN];
void fg(int x){
    for(int i=x-1;i>=1&&a[x]-a[i]<=d;i--){
        dp[x]+=dp[i]+f[i];f[x]++;
        if(a[x]-a[i])
    }
        
    
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(C<=10){
        for(int x=1;x<=n;x++)
            fg(x);
    }
    else
        cout<<0<<'\n';
    
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    ll t;
    //t=1;
    cin>>C>>t;
    while(t--)
        solve();
    return 0;
}
