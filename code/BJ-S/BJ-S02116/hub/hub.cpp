#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n, m;cin>>n>>m;
    for(int i = 2;i<=n;i++){
        int x, y;cin>>x>>y;
    }
    cout<<(max(1ll,(int)ceil(1.0*(n-2*m)/2)))<<endl;
    return ;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, t;cin>>c>>t;
    while(t--){solve();}
    return 0;
}
