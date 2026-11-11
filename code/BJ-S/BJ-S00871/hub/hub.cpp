#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,k;
vector<int> tree[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t,c;
    cin >>c>> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1;i < n;i++){
            int u,v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }
    cout << "没时间了,抱歉\n";
    return 0;
}
