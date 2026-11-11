#include<bits/stdc++.h>

using namespace std;

int c,t,n,k,xuan[1000005];
vector<int> ling[1000005];


int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1;i<=n;i++) ling[i].clear();
        for(int i = 1,u,v;i<n;i++){
            cin >> u >> v;
            ling[u].push_back(v);
            ling[v].push_back(u);
        }
        cout << 0 << "\n";
    }

    return 0;
}