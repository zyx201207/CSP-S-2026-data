#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int MAXM=500005;
int c,n,m,d,q;
int w[MAXM];
long long dp[MAXN][MAXN];
vector<pair<int,int> > v[MAXM];
vector<pair<int,int> > edge[MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			dp[i][j]=INT_MAX*(1ll<<20);
		}
	}
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k,a,t;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&t);
			v[a].push_back(make_pair(i,t));
			edge[i].push_back(make_pair(a,t));
		}
		sort(edge[i].begin(),edge[i].end());
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			int l=0;
			for(pair<int,int> k:edge[i]){
				if(k.first<edge[j][l].first) continue;
				while(k.first>edge[j][l].first){
					l++;
					if(l==int(edge[j].size()))
						break;
				}
				if(l==int(edge[j].size())) break;
				dp[i][j]=min(dp[i][j],k.second*1ll+edge[j][l].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=INT_MAX*(1ll<<20);
		for(pair<int,int> i:v[x]){
			for(pair<int,int> j:v[y]){
				ans=min(ans,dp[i.first][j.first]+i.second+j.second);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
