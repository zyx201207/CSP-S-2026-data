#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int M=5e5+10;
const int N=505;
const int Q=1e5+10;
const int T=8e4+10;
int n,c,m,d,q,k,w[M],a[N],t[N],x[Q],y[Q];
bool vis[M];
struct Node{
    int id;bool type;
    vector<Node*> child;
} nodes[M];
struct Edge{
    Node* u;Node* v;int l;
};
vector<Node> G;
vector<Edge> E;
vector<vector<int>> g(M);
void dfs(int idx,int bg,int ed)
{
    ll res=0;
    if(idx==bg) res+=w[idx];
    for(int v:g[idx])
    {

    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    Node* adres;
    for(int i=1;i<=m;++i)
    {
        cin>>w[i];
        Node nd;
        nd.type=0;
        nd.id=i;
        nodes[i]=nd;
        G.push_back(nd);
    }
    for(int i=1;i<=n;++i)
    {
        cin>>k;
        for(int j=1;i<=k;++j)
        {
            cin>>a[j]>>t[j];

            Node nd;
            nd.id=a[j],nd.type=1;
            nd.child.push_back(&nodes[i]);
            G.push_back(nd);
            Edge eg;
            if(j>1) {
                nd.child.push_back(adres);
                adres->child.push_back(&nd);
                Edge e;
                e.u=adres;
                e.v=&nd;
                e.l=0;
            }
            Node* adres=&(G.back());
            nodes[i].child.push_back(adres);
        }
    }
    for(int i=1;i<=q;++i)
    {
        cin>>x[i]>>y[i];
    }
    return 0;
}