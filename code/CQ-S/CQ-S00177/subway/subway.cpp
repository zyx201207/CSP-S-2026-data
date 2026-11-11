#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 86;
ll c,n,m,d,q,a[205][N],t[205][N],w[N],k[205],bj[N],v[3005][3005],ans;
struct node{
    ll x,val;
};
void dfs(ll x,ll y,ll sum){
    if(x == y){
        ans = min(ans,sum);
        return ;
    }
    for(int i = 1;i <= m;i++){
        if(v[x][i] && !bj[i]){
            bj[i] = 1;
            dfs(i,y,sum += v[x][i]);
            bj[i] = 0;
        }
    }
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("sudway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++) cin>>w[i];
    for(int i = 1;i <= n;i++){
        cin>>k[i];
        for(int j = 1;j <= k[i];j++) cin>>a[i][j]>>t[i][j];
        for(int j = 1;j <= k[i];j++){
            for(int l = 1;l <= k[i];l++){
                if(j == l) continue;
                ll x = a[i][j],y = a[i][l],z = t[i][j] + t[i][l];
                if(v[x][y]) v[x][y] = min(v[x][y],z),v[y][x] = min(v[y][x],z);
                else v[x][y] = z,v[y][x] = z;
            }
        }
    }
    while(q--){
        memset(bj,0,sizeof bj);
        ll x,y;
        cin>>x>>y;
        bj[x] = 1;
        ans = LONG_LONG_MAX;
        dfs(x,y,w[x] + w[y]);
        cout<<ans<<endl;
    }
	return 0;
}