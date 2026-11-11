#include <bits/stdc++.h>
#define ll long long
#define fst first
#define snd second
using namespace std;
const int N = 510,M = 5e5+10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int C,n,m,d,q;
ll dis[N][N];
ll w[M];
struct node{
	int a;
	ll t;
};
vector <node> s[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for(int i = 1;i<=m;i++)scanf("%lld",w+i);
	for(int i = 1,k;i<=n;i++){
		dis[i][i] = 0;
		scanf("%d",&k);
		int a;
		ll t;
		for(int j = 1;j <= k;j++){
			scanf("%d%lld",&a,&t);
			s[a].push_back({i,t});
		}
	}

	for(int i = 1;i<=m;i++){
		for(int j = 1;j < s[i].size();j++){
			for(int k = 0;k < j;k++){
				int s1 = s[i][j].a,s2 = s[i][k].a;
				ll v1 = s[i][j].t,v2 = s[i][k].t;
				dis[s1][s2] = min(dis[s1][s2],v1+v2);
				dis[s2][s1] = min(dis[s2][s1],v1+v2);
			}
		}
	}
	
	for(int k = 1;k <= n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j <= n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]); 
			}
		}
	}
	
	int x,y;
	ll ans,res;
	while(q--){
		scanf("%d%d",&x,&y);
		if(x == y){
			printf("0\n");
			continue;
		}
		ans = INF;
		for(int i = 0;i < s[x].size();i++){
			for(int j = 0;j < s[y].size();j++){
				res = s[x][i].t + s[y][j].t + dis[s[x][i].a][s[y][j].a];
				ans = min(res,ans);
			}
		}
		ans += w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 480 479521 20 90000
0 480 479521 2 90000


fc E:\FJ-S01163\subway\subway.out E:\FJ-S01163\subway\subway7.ans 
*/
