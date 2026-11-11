#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,n,m,q,w[N],k[510],x,y,d,xx,yy,dp[510][510],ans,ans1,ans2;
struct f{
	int v,w;
};
vector<f> dian[N];
bool flag1,flag2;
void floyd(){
	for (int i=1;i<=n;i++){
		dp[i][i]=0;
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
void work(){
	for (int i=1;i<=m;i++){
		for (auto u:dian[i]){
			int v1=u.v;
			int w1=u.w;
			for (auto uu:dian[i]){
				int v2=uu.v;
				int w2=uu.w;
				if (v1!=v2){
					dp[v1][v2]=min(dp[v1][v2],w1+w2);
				}
			}
		}
	}
	floyd();
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>x>>y;
			dian[x].push_back({i,y});
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			dp[i][j]=1e17;
		}
	}
	work();
	while (q--){
		cin>>x>>y;
		ans=1e18;
		ans1=0;
		ans1+=w[x];
		ans1+=w[y];
		ans2=1e18;
		for (auto i:dian[x]){
			for (auto j:dian[y]){
				ans2=min(ans2,j.w+i.w+dp[i.v][j.v]);
			}
		}
		cout<<ans1+ans2<<"\n";
	}
	return 0;
}
