#include<bits/stdc++.h>
#define int long long
#define fr(i,l,r) for(int (i)=(l);(i)<=(r);i++)
#define fd(i,r,l) for(int (i)=(r);(i)>=(l);i--)
using namespace std;

void solve(){
    int n,k;cin>>n>>k;
    fr(i,1,n){
        int u,v;cin>>u>>v;
    }
    cout<<ceil(n*1.0/8-k*1.0/4)+1<<'\n';
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;cin>>c>>T;
    while(T--)solve();
}