#include<bits/stdc++.h>
using namespace std;
int INF=0x3f3f3f3f;
int dp[5005][5005];
int ss[5005][5005];
long long x[1000005];
int last[1000005],pre[1000005];
int ls[1000005],ps[1000005];
int n;
int c,t;
long long d;
long long ans=0;
int l,r;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(ss,0,sizeof(ss));
		memset(dp,0x3f,sizeof(dp));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		l=1;
		for(int i=1;i<=n;i++){
			while(x[i]-x[l]>d)l++;
			pre[i]=l;
		}
		r=1;
		for(int i=1;i<=n;i++){
			while(x[r]-x[i]<=d&&r<=n)r++;
			last[i]=r-1;
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=ss[i][j]=INF;
		for(int l=1;l<=n;l++){
			for(int i=1;i<=n-l+1;i++){
				int j=i+l-1;
				int minn=0x3f3f3f3f,minsum=0;
				if(x[j]-x[i]<=d){
					dp[i][j]=1;
					if(i==j)dp[i][j]=0;
					ss[i][j]=1;
				}
				else{
					int ls=last[i];
					if(ls==i)continue;
					for(int k=max(i+1,ls-2);k<=ls;k++){
						if(x[k]-x[i]>d)break;
						if(minn>dp[i][k]+dp[k][j]){
							minn=dp[i][k]+dp[k][j];
							minsum=ss[i][k]*ss[k][j];
						}
						else if(minn==dp[i][k]+dp[k][j]){
							minsum+=ss[i][k]*ss[k][j];
						}
					}
					if(minsum==2)ans++;	
					else if(minsum>=3)minsum=3;
					ss[i][j]=minsum;
					dp[i][j]=minn;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
