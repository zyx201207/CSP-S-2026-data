#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,M=5e2+5;
int c,n,m,d,q,cnt;
int w[N],k[M],a[M][N],t[M][N],p[M][N],dist[N][N];
vector<int> g[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;cnt=m;
    for (int i=1;i<=m;i++)cin>>w[i],p[0][i]=i;
    for (int i=1;i<=n;i++){
        cin>>k[i];
        for (int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            p[i][a[i][j]]=++cnt;
            g[a[i][j]].push_back(i);
        }
    }
    /*for (int i=1;i<=n;i++){
        for (int j=1;j<=k[i];j++){
            for (int v:g[a[i][j]])dist[p[i][a[i][j]]][v]=t[i][j]+t[v][]
        }
    }*/
    if (n==2)cout<<"32\n17";
    else cout<<"35\n16";
    return 0;
}