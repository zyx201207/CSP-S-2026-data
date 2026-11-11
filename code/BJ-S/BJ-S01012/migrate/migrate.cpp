#include<bits/stdc++.h>
#define int long long
#define fr(i,l,r) for(int (i)=(l);(i)<=(r);i++)
#define fd(i,r,l) for(int (i)=(r);(i)>=(l);i--)
using namespace std;

void solve(){
    int n,d,a,b,x;cin>>n>>d>>a>>b;
    fr(i,1,n-2)cin>>x;
    if(d<=b-a)cout<<"0\n";
    else cout<<max(n-2*d/(b-a)+1,0ll)<<'\n';
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--)solve();
    return 0;
}