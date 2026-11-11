#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int gm,n,m,d,q,a[N][N],b[N],t[N][N],dp[N][N],x,y,k[N],fa[N],ta[N][N];
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>gm>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		fa[i]=i;
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			ta[a[i][j-1]][a[i][j]]=t[i][j]+t[i][j-1];
			ta[a[i][j]][a[i][j-1]]=ta[a[i][j-1]][a[i][j]];
			if(find(a[i][j])!=find(a[i][j-1]))fa[a[i][j]]=fa[a[i][j-1]];
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=2;j<=k[i];j++){
			dp[a[i][j]][a[i][j-1]]=min(dp[a[i][j]][a[i][j-1]],t[i][j]+t[i][j-1]);
			dp[a[i][j-1]][a[i][j]]=dp[a[i][j]][a[i][j-1]];
		}
	}
	for(int s=1;s<=m;s++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j){
					dp[i][j]=0;
					continue;
				}
				dp[i][j]=min(dp[i][s]+dp[s][j],dp[i][j]);
				if(find(i)==find(j))dp[i][j]-=ta[i][j];
			}
		}
	}
	while(q--){
		cin>>x>>y;
		int sum=dp[x][y]+b[x]+b[y];
		cout<<sum<<"\n";
	}
	return 0;
}
