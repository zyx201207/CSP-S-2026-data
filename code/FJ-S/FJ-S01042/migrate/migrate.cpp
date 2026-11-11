#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50,M=5e3+50;
int a[N],dp[M][M],maxn[M][M],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			if(d/(a[2]-a[1])==1)cout<<0<<'\n';
		    else cout<<n-d/(a[2]-a[1])*2+1<<'\n';
		    continue;
		}for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=0,maxn[i][j]=1e9;//方案与最小
		for(int i=1;i<=n;i++){
			int l=i,a1=1,a2=0;dp[i][i]=1;maxn[i][i]=0;
			for(int j=i+1;j<=n;j++){
		    	while(a[j]-a[l]>d){
		    		a1-=dp[i][l];
					if(a1<=0)a1=a2,a2=0;
					++l;
				}
		    	maxn[i][j]=maxn[i][l]+1;
		    	dp[i][j]=a1;
				if(l==j)dp[i][j]=0;
				if(dp[i][j]>3)dp[i][j]=3;
				a2+=dp[i][j];
				if(dp[i][j]==2)ans++;
			}
		}cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}