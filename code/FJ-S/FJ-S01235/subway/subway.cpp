#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
struct qwq{
	int v,w;
	qwq(int V = 0,int W = 0){
		v = V;
		w = W;
	}
};
int c,n,m,d,q,l,x,y,t[500005];
long long dis[505][505],ans;
vector<qwq> edge[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> t[i];
	for(int i = 0;i < n;i++)
		for(int j = i+1;j < n;j++)
			dis[i][j] = dis[j][i] = 0x3f3f3f3f3f3f3f3f;
	for(int i = 0;i < n;i++){
		cin >> l;
		for(int j = 0;j < l;j++){
			cin >> x >> y;
			for(qwq k : edge[x])
				dis[i][k.v] = dis[k.v][i] = min(dis[i][k.v],0ll+y+k.w);
			edge[x].push_back(qwq(i,y));
		}
	}
	for(int k = 0;k < n;k++)
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i = 0;i < q;i++){
		ans = 0x7fffffffffffffff;
		cin >> x >> y;
		for(qwq j : edge[x])
			for(qwq k : edge[y])
				ans = min(ans,j.w+k.w+dis[j.v][k.v]);
		cout << ans+t[x]+t[y] << '\n';
	}
	return 0;
}
