#include<bits/stdc++.h>
using namespace std;

long long hsh(int x,int y){
	return x*1000000007+y*1000000007*1000000007;
}

int c,n,m,d,q,w[500005],K[505];
long long ans=LONG_LONG_MAX,dp[505][505];
vector<int> a[505],b[500005];
unordered_map<long long,int> t;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=i)dp[i][j]=1000000000;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&K[i]);
		for(int j=1;j<=K[i];j++){
			int x,y;
			scanf("%d %d",&x,&y);
			a[i].push_back(x);
			t[hsh(x,i)]=y;
			//cout<<t[hsh(x,i)]<<"]\n";
			for(int k=0;k<b[x].size();k++){
				int u=b[x][k];
				//cout<<dp[u][i]<<'\n';
				dp[u][i]=min(dp[u][i],t[hsh(x,i)]+t[hsh(x,u)]+0ll);
				dp[i][u]=dp[u][i];
				//cout<<i<<' '<<u<<' '<<dp[i][u]<<'\n';
			}
			b[x].push_back(i);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		for(int j=0;j<b[x].size();j++){
			for(int k=0;k<b[y].size();k++){
				int u=b[x][j],v=b[y][k];
				ans=min(ans,dp[u][v]+t[hsh(x,u)]+t[hsh(y,v)]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
