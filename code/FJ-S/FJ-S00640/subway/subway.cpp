#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+2;
int c,n,m,d,q,hd,ed,cnt;
int w[N],k[502],rd[N][2],sum[502];
int ct[N],ps[N][25][2];
int dp[502][502];
bool book[502][502];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k[i];sum[i]=sum[i-1]+k[i];
		for(int j=1;j<=k[i];j++) cnt++,cin >> rd[cnt][0] >> rd[cnt][1],ps[rd[cnt][0]][++ct[rd[cnt][0]]][0]=i,ps[rd[cnt][0]][ct[rd[cnt][0]]][1]=rd[cnt][1];
	}
	
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dp[i][j]=LONG_LONG_MAX;
	
	for(int kk=1;kk<=n;kk++)
		for(int i=1;i<=k[kk];i++)
			for(int j=1;j<=ct[rd[sum[kk-1]+i][0]];j++)
				book[kk][ps[rd[sum[kk-1]+i][0]][j][0]]=book[ps[rd[sum[kk-1]+i][0]][j][0]][kk]=1,dp[kk][ps[rd[sum[kk-1]+i][0]][j][0]]=min(dp[kk][ps[rd[sum[kk-1]+i][0]][j][0]],rd[sum[kk-1]+i][1]+ps[rd[sum[kk-1]+i][0]][j][1]);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=min(dp[i][j],dp[j][i]),dp[j][i]=dp[i][j];

	int ctt=n-1;
	for(int i=2;i<=n;i++)
		if(book[1][i]) ctt--;
	
	while(ctt){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					if(i!=j &&j!=k && i!=k){
						if(dp[i][j]!=LONG_LONG_MAX && dp[j][k]!=LONG_LONG_MAX) dp[i][k]=min(dp[i][k],dp[i][j]+dp[j][k]);
						if(i==1 && !book[1][k]) book[1][k]=1,ctt--;
					}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[j][i]),dp[j][i]=dp[i][j];
	}
	
	for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					if(i!=j &&j!=k && i!=k){
						if(dp[i][j]!=LONG_LONG_MAX && dp[j][k]!=LONG_LONG_MAX) dp[i][k]=min(dp[i][k],dp[i][j]+dp[j][k]);
					}	
	for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[j][i]),dp[j][i]=dp[i][j];				
	
	while(q--){
		cin >> hd >> ed;int minn=LONG_LONG_MAX;
		for(int i=1;i<=ct[hd] &&minn;i++)
			for(int j=1;j<=ct[ed];j++)
				minn=min(minn,dp[ps[hd][i][0]][ps[ed][j][0]]+ps[hd][i][1]+ps[ed][j][1]);
		cout << minn+w[hd]+w[ed] << "\n";
	}
	return 0;	
}
