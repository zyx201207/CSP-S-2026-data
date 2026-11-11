#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=1e9;
const ll INF=1e18;

void solve(){
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    vector<int>w(m+1);
    vector<vector<int>> line(n+1), t(n+1);
    for (int i=1; i<=m; i++)cin>>w[i];
    for (int i=1; i<=n; i++){
        int l;cin>>l;
        line[i].resize(l+1);
        t[i].resize(l+1);
        for (int j=1; j<=l; j++){
            cin>>line[i][j]>>t[i][j];
        }
    }
}

int main(){
    // freopen("subway.in","r",stdin);
    // freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}