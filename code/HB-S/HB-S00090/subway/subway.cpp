#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M=5e2+5,N=505;

int c,n,m,d,q,k[N],w[M],t[N][N];

vector<int> a[N];

vector<int> g[N][N];


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin >> x >> y;
            t[x][i]=y;
            a[i].push_back(x);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<a[i].size();j++){
            int u=a[i][j-1],v=a[i][j];
            g[u][i].push_back(v);
            g[v][i].push_back(u);
        }
    }

    for(int i=1;i<=m;i++){
        cerr << "station " << i << '\n';
        for(int j=1;j<=n;j++){
            cerr << "line " << j << '\n';
            for(int v:g[i][j]) cerr << v << ' ';
            cerr << '\n';
        }
    }
    return 0;
}
//g++ -o subway subway.cpp -O2 -std=c++14 -static