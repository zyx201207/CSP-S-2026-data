//GZ-S00126 贵阳市第一中学 谢云龙 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
int n,m;
ll mp[N][N],dp[N][N];
vector<ll>t[M];
vector<int>to[M];
ll a[M];
void floyd(){
	memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=m;i++){
		for(int j=0;j<t[i].size();j++){
			for(int k=0;k<t[i].size();k++){
				if(j!=k){
					mp[to[i][j]][to[i][k]]=min(mp[to[i][j]][to[i][k]],t[i][j]+t[i][k]);
					mp[to[i][k]][to[i][j]]=mp[to[i][j]][to[i][k]];
	//				oii aii iioaioii iio iia ioaoaoi oii aii iioaioii iio iia ioaoaoi   oiiai!
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=mp[i][j];
		}
		dp[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&i!=k&&j!=k){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
	}
}
ll qmn(int x,int y){
	ll ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<t[x].size();i++){
		for(int j=0;j<t[y].size();j++){
			ans=min(ans,dp[to[x][i]][to[y][j]]+t[x][i]+t[y][j]);
		}
	}
	ans+=a[x]+a[y];
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,d,q,k,x,y;
	ll w;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>w;
			t[x].push_back(w);
			to[x].push_back(i);
		}
	}
	floyd();
	while(q--){
		cin>>x>>y;
		cout<<qmn(x,y)<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
