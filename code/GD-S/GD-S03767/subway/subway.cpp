#include<bits/stdc++.h>
using namespace std;
#define int long long
#define AC return 0
#define endl '\n'

const int N=5e5+5;

int c,n,m,d,q;
int w[N];
bool vis[N];

struct edge{
    int u,v,val;
};
vector<edge> adj[N];


signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k,a[n+1],t[n+1];
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<k;j++){
            adj[i].push_back(a[j],a[j+1],t[j]+t[j+1]);
            adj[i].push_back(a[j+1],a[j],t[j]+t[j+1]);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<ans<<endl;
    }
    AC;
}
//我再也不不背模板了