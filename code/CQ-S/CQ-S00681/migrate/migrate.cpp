#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
int c,t;
ll a[maxn],d,n,dp[maxn];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(c>=11&&c<=12){
        ll tmp=d/(a[2]-a[1]);
        if(tmp<=1) cout<<0<<"\n";
        else  cout<<max(0LL,n-2*tmp+1)<<"\n";
    }else if(c>=13&&c<=14) cout<<(n/2-1)*(n/2)<<"\n";
    else cout<<n*(n-1)/2<<"\n";
}  
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--) solve();
    return 0;
}