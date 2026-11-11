#include<bits/stdc++.h>
using namespace std;
//#define int long long

int c,t,n,d,a[2000005],dp[5005][5005],cmp1[5005][5005],cmp2[5005][5005];
void init(){
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=0x3f3f3f3f;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(d<a[2]-a[1]){
			cout<<"0\n";
			continue;
		}
		if(c==11||c==12){
			int tmp=(a[2]-a[1])/d+1;
			if(tmp==1)cout<<"0\n";
			else if(tmp==2)cout<<max(0,n-3)<<'\n';
			else cout<<tmp-2<<'\n';
			continue;
		}
		init();
		for(int i=1;i<=n;i++){
			dp[i][i]=0;
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d)dp[i][j]=1;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(i!=j&&j!=k)
						if(dp[i][j]>dp[i][k]+dp[k][j])cmp2[i][j]=cmp1[i][j],cmp1[i][j]=dp[i][j],dp[i][j]=dp[i][k]+dp[k][j];
						else if(cmp1[i][j]>dp[i][k]+dp[k][j])cmp2[i][j]=cmp1[i][j],cmp1[i][j]=dp[i][k]+dp[k][j];
						else if(cmp2[i][j]>dp[i][k]+dp[k][j])cmp2[i][j]=dp[i][k]+dp[k][j];
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&dp[i][j]==cmp1[i][j]&&cmp1[i][j]!=cmp2[i][j])ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
