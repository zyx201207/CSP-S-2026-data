#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
const long long inf=1e18;
int c,n,m,d,q;
long long dis[N][N],w[M],ans;
vector<int>a[M],t[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=inf;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int x,y;
			cin>>x>>y;
			a[x].push_back(i);
			t[x].push_back(y);
		}
	}
	for(int i=1;i<=m;i++){
		int len=a[i].size();
		for(int j=0;j<len;j++){
			for(int k=0;k<len;k++){
				if(j==k)continue;
				dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],0ll+t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=inf;
		int len1=a[x].size(),len2=a[y].size();
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				ans=min(ans,t[x][i]+t[y][j]+dis[a[x][i]][a[y][j]]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
