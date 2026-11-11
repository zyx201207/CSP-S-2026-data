#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N =2e5+10;
struct zz{
ll wz,su;
};
ll c,n,m,d,q,w[N],k[555],a[555][N],t[555][N],x,y,sum=1e8,vis[N];
queue<zz>qx;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for (int i = 1;i <= n;i++){
        cin >> k[i];
        for (int j = 1;j <= k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 1;i <= q;i++){
        cin >> x >> y;
        ll ans = w[x]+w[y];
        sum=1e8;
        memset(vis,63,sizeof(vis));
        qx.push({x,0});
        while (!qx.empty()){
            auto c = qx.front();
            qx.pop();
            if (vis[c.wz]>c.su)vis[c.wz]=c.su;
            else continue;
            for (int i = 1;i <= n;i++){
                bool ha=0;
                for (int j = 1;j <= k[i];j++){
                    if (a[i][j]==c.wz){
                        ha=1;
                        break;
                    }
                }
                if (!ha)continue;
                for (int j = 1;j <= k[i];j++){
                    if (a[i][j]==c.wz)continue;
                    ll as=0;
                    for (int s = 1;s <= k[i];s++)if (a[i][s]==c.wz){as=s;break;}
                    qx.push({a[i][j],c.su+t[i][j]+t[i][as]});
                }
            }
        }
        cout << vis[y]+ans<<"\n";
    }
    return 0;
}
