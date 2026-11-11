#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5+10;
const int N=510;
const ll inf=5e14+10;
ll w[M];
struct yi{
    int k;
    vector<int> a;
    vector<ll> b;
}sh[N];
ll f[N][N];
vector<int> tu[M];
vector<ll> tu2[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        cin >> sh[i].k;
        for(int j=1;j<=sh[i].k;j++){
            ll a,b;
            cin >> a >> b;
            sh[i].a.push_back(a);
            sh[i].b.push_back(b);
            tu[a].push_back(i);
            tu2[a].push_back(b);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sh[i].k;j++){
            for(int o=0;o<tu[sh[i].a[j]].size();o++){
                int k=tu[sh[i].a[j]][o];
                if(k==i) continue;
                f[i][k]=min(f[i][k],sh[i].b[j]+tu2[sh[i].a[j]][o]);
                f[k][i]=min(f[k][i],f[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }*/
    while(q--){
        int u,v;
        cin >> u >> v;
        ll ans=inf;
        for(int o=0;o<tu[u].size();o++){
            int i=tu[u][o];
            for(int qw=0;qw<tu[v].size();qw++){
                int j=tu[v][qw];
                ans=min(ans,f[i][j]+tu2[u][o]+tu2[v][qw]);
            }
        }
        cout << ans+w[u]+w[v] << "\n";
    }
    return 0;
}
