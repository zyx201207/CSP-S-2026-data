#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500005],k,tmpa,tmpt,x,y,dis[505][505],ans;
int t[500005][505];
vector<pair<ll,ll> > vec[500005];
pair<ll,ll> tmp1,tmp2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i = 1;i <= m;i++)scanf("%lld",&w[i]);
	for(ll i = 1;i <= n;i++){
		dis[i][i] = 0;
		scanf("%lld",&k);
		for(ll j = 1;j <= k;j++){
			scanf("%lld%lld",&tmpa,&tmpt);
			t[tmpa][i] = tmpt;
			vec[tmpa].push_back(make_pair(i,tmpt));
		}
	}
	for(ll i = 1;i <= m;i++){
		for(ll j = 0;j <= vec[i].size() - 1;j++){
			tmp1 = vec[i][j];
			for(ll k = j + 1;k <= vec[i].size() - 1;k++){
				tmp2 = vec[i][k];
				dis[tmp1.first][tmp2.first] = dis[tmp2.first][tmp1.first] = min(dis[tmp1.first][tmp2.first],tmp1.second + tmp2.second);
			}
		}
	}
	for(ll k = 1;k <= n;k++)for(ll i = 1;i <= n;i++)for(ll j = 1;j <= n;j++)if(dis[i][k] + dis[k][j] < dis[i][j])dis[i][j] = dis[i][k] + dis[k][j];
	for(ll i = 1;i <= q;i++){
		scanf("%lld%lld",&x,&y);
		ans = -1;
		for(ll j = 0;j <= vec[x].size() - 1;j++){
			tmp1 = vec[x][j];
			for(ll k = 0;k <= vec[y].size() - 1;k++){
				tmp2 = vec[y][k];
				if(ans == -1)ans = dis[tmp1.first][tmp2.first] + w[x] + w[y] + t[x][tmp1.first] + t[y][tmp2.first];
				else ans = min(ans,dis[tmp1.first][tmp2.first] + w[x] + w[y] + t[x][tmp1.first] + t[y][tmp2.first]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
