#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+5;

int c,n,m,d,q;
int w[N];
/*
struct cla{
    int to,t;
};
vector<cla> G[N];*/
vector<pair<int,int>> station[N];
vector<int> cross[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int k;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int u,t;
            cin>>u>>t;
        //    G[i].push_back({u,t});
            station[u].push_back(make_pair(i,t));
            cross[u].push_back(i);
        }

    }
    int x,y;
    while(q--){
        cin>>x>>y;
        cout<<w[x]+w[y]<<'\n';
    }
}
