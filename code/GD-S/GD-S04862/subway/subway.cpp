#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e18;
long long dp[505][505],c,n,m,d,q,w[500005],k[505],vis[500005],las[500005];
int s[500005][505];
vector<long long> a[505],t[505],node[500005],tf[500005];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a1,t1;
			cin>>a1>>t1;
			a[i].push_back(a1);
			t[i].push_back(t1);
			s[a1][i]=t1;
			node[a1].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=MAXN;
		}
		dp[i][i]=0;
	} 
	for(int i=1;i<=n;i++){
		for(int k1=0;k1<k[i];k1++){
			vis[a[i][k1]]=i;
			las[a[i][k1]]=k1;
		}
	//	cout<<q<<endl;
		for(int j=i+1;j<=n;j++){
			for(int k2=0;k2<k[j];k2++){
				if(vis[a[j][k2]]==i){
					dp[i][j]=min(dp[i][j],t[j][k2]+t[i][las[a[j][k2]]]);
					dp[j][i]=dp[i][j];
				}
			}
		}
	}
	floyd();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long len1=node[x].size(),len2=node[y].size(),ans=MAXN;
		for(int j1=0;j1<len1;j1++){
			for(int j2=0;j2<len2;j2++){
				ans=min(ans,dp[node[x][j1]][node[y][j2]]+s[x][node[x][j1]]+s[y][node[y][j2]]);
			}
		} 
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
