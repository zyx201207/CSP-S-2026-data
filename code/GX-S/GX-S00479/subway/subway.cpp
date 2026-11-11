#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+5;
typedef pair<ll,ll> P;
ll read(){
    char x = getchar();
    ll a = 1,ans = 0;
    while(x < '0'||x > '9'){
        if(x == '-')a = -1;
        x = getchar();
    }
    while(x >= '0'&&x <= '9'){
        ans = ans*10+x-'0';
        x = getchar();
    }
    return ans*a;
}
ll w[N];
ll pth[505][505];
vector<P> a[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c = read(),n = read(),m = read(),d = read(),q = read();
    memset(pth,0x3f,sizeof(pth));
    for(int i = 1;i <= m;i ++){
        w[i] = read();
    }
    for(int i = 1;i <= n;i ++){
        pth[i][i] = 0;
        ll k = read();
        while(k--){
            ll x = read(),y = read();
            a[x].push_back(make_pair(i,y));
        }
    }
    for(int i = 1;i <= m;i ++){
        if(a[i].size() <= 1)continue;
        for(int j = 0;j < a[i].size();j ++){
            for(int k = j+1;k < a[i].size();k ++){
                ll x = a[i][j].first,y = a[i][k].first;
                pth[x][y] = pth[y][x] = min(pth[x][y],a[i][j].second+a[i][k].second);
            }
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            for(int k = 1;k <= n;k ++){
                if(j != k &&pth[j][k] > pth[j][i] + pth[i][k]){
                    pth[j][k] = pth[k][j] = pth[j][i] + pth[i][k];
                }
            }
        }
    }
    while(q--){
        ll x = read(),y = read();
        ll ans = 100000000000000000ll;
        for(int i = 0;i < a[x].size();i ++){
            for(int j = 0;j < a[y].size();j ++){
                ans = min(ans,pth[a[x][i].first][a[y][j].first]+w[x]+w[y]+a[x][i].second+a[y][j].second);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
