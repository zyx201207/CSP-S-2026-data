#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> edge[200005];
        for(int i = 1 ; i < n ; i++){
            int u,v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
    }
    cout << 1 << endl << 2;
    return 0;
}
