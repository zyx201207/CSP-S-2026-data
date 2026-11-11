#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int N=5e5+10,M=505;
struct node{
	int st;
	ll len;
};
int c,n,m,d,Q;
ll w[N];
ll dp[M][M];
int f[M];
priority_queue<PII,vector<PII>,greater<PII>> q;
ll e[M][M];
vector<ll> v1[M];
vector<node> v[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		int al;
		ll tl;
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&al,&tl);
			v1[i].push_back(al);
			v[al].push_back({i,tl});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=0x3f3f3f3f3f3f;
			e[i][j]=0x3f3f3f3f3f3f;
		}
	}
	for(int i=1;i<=n;i++){
		int l=v1[i].size();
		for(int j=0;j<l;j++){
			int le=v[v1[i][j]].size();
			if(le>1){
				ll o;
				for(int k=0;k<le;k++){
					if(v[v1[i][j]][k].st==i){
						o=v[v1[i][j]][k].len;
						break;
					}
				}
				for(int k=0;k<le;k++){
					if(v[v1[i][j]][k].st!=i){
						e[i][v[v1[i][j]][k].st]=min(e[i][v[v1[i][j]][k].st],o+v[v1[i][j]][k].len);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		while(!q.empty()) q.pop();
		memset(f,0,sizeof(f));
		dp[i][i]=0;
		q.push({0,i});
		while(!q.empty()){
			PII qq=q.top();
			q.pop();
			int s=qq.second;
			ll z=qq.first;
			if(f[s]==1) continue;
			f[s]=1;
			for(int j=1;j<=n;j++){
				if(s==j) continue;
				if(dp[i][j]>z+e[s][j]){
					dp[i][j]=z+e[s][j];
					q.push({dp[i][j],j});
				}
			}
		}
	}
	int x,y;
	while(Q--){
		scanf("%d%d",&x,&y);
		ll mi=0x3f3f3f3f3f3f;
		int l1=v[x].size();
		int l2=v[y].size();
		for(int i=0;i<l1;i++){
			for(int j=0;j<l2;j++){
				if(v[y][j].st==v[x][i].st) mi=min(mi,v[x][i].len+v[y][j].len);
				else mi=min(mi,v[x][i].len+v[y][j].len+dp[v[y][j].st][v[x][i].st]);
			}
		}
		printf("%lld\n",mi+w[x]+w[y]);
	}
	return 0;
} 



