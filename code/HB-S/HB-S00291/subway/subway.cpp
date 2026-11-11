#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=505;
const int MAXM=5e5+5;
const ll INF=1e18;
struct node{
    ll i,t;
};

ll c,n,m,d,q,w[MAXM],dist[MAXN][MAXN];
vector<node> v[MAXM];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        int ki; cin >> ki;
        for(int j=1;j<=ki;j++){
            ll aij,tij; cin >> aij >> tij;
            v[aij].push_back({i,tij});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=INF;
            if(i==j){
                dist[i][j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(node x:v[i]){
            for(node y:v[i]){
                if(x.i==y.i)continue;
                dist[x.i][y.i]=x.t+y.t;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // if(i==j||j==k||i==k)continue;
                dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }
    while(q--){
        int l,r; cin >> l >> r;
        ll ans=INF;
        for(node x:v[l]){
            for(node y:v[r]){
                ans=min(ans,dist[x.i][y.i]+x.t+y.t);
            }
        }
        ans+=w[l]+w[r];
        cout << ans << "\n";
    }
    return 0;
}