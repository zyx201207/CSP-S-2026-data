#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

int n,k;
vector<int> G[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,T;
    cin>>c>>T;

    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v
            G[u].push_back(v);
            G[v].push_back(u);

        }cout<<sqrt(n)<<'\n';
    }

}
