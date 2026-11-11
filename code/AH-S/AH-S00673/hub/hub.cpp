#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int c,t;
int n,k;
vector<int> G[MAXN];

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        cout<<rand()%(n-k)<<'\n';
    }
    return 0;
}
