#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,n,m,d,q;
struct node{
    int x,w;
};
int val[500005];
int f[505][505];
vector<node> a[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> val[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        for(int j=1;j<=k;j++){
            int x,w;
            cin >> x >> w;
            a[x].push_back((node){i,w});
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=m;i++){
        for(auto [x,w1]:a[i]){
            for(auto [y,w2]:a[i]){
                if(x!=y){
                    f[x][y] = min(f[x][y],w1+w2);
                    f[y][x] = min(f[y][x],w1+w2);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        f[i][i] = 0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            cout << f[i][j] << " ";
//        }
//        cout << endl;
//    }
    while(q--){
        int x,y,ans = 1e18;
        cin >> x >> y;
        for(auto [i,w1]:a[x]){
            for(auto [j,w2]:a[y]){
                ans = min(ans,w1+w2+f[i][j]);
            }
        }
//        cout << "LJ:" << q << " " << ans+val[x]+val[y] << endl;
        cout << ans+val[x]+val[y] << endl;
    }
    return 0;
}

