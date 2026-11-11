#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int c,t;
int n,k;
vector<int> E[N];
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1;i < n;i++){
            int u,v;
            cin >> u >> v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        cout << (k + 1) / 2 << '\n';
    }
    return 0;
}

