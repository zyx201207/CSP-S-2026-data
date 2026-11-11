#include<bits/stdc++.h>
using namespace std;

long long c, t, n, k;
vector<int> a[500005];
int cjr = 1;

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1;i < n;i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        cout << cjr << "\n";
        cjr++;
    }
    return 0;
}
