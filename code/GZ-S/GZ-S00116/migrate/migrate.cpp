//贵阳第一中学 GZ-S00116 胡祺然 
#include<iostream>
#define int long long
using namespace std;
const int N=2e6+10;
int c,T,n,d,x[N],dp[N][2],g[N],b[N],cnt,ans,s[N][2];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			g[i]=0;
			b[i]=0;
			s[i][1]=0;
			s[i][0]=0;
			dp[i][0]=0;
			dp[i][1]=0;
		}
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		cnt=1;
		for(int i=1;i<=n;i++){
			while(cnt<n&&x[cnt+1]-x[i]<=d)cnt++;
			g[i]=cnt;
		}
		cnt=n;
		for(int i=n;i>=1;i--){
			while(cnt>1&&x[i]-x[cnt-1]<=d)cnt--;
			b[i]=cnt;
		}
		b[n+1]=n+10;
		for(int i=1;i<=n;i++){
			s[i][1]=s[i-1][1];
			s[i][0]=s[i-1][0];
			if(b[i]==i)continue;
			if(b[i]==b[i+1])continue;
			dp[i][0]+=dp[b[i]][0];
			dp[i][0]+=(b[i+1]-b[i]);
			dp[i][1]+=dp[b[i]][1];
			if(b[i]!=i-1&&g[b[i]+1]==i)dp[i][1]+=dp[b[i]+1][0];
			else if(b[i]!=i-1)ans+=dp[b[i]+1][0];
		}
		for(int i=1;i<=n;i++){
			ans+=dp[i][1];
		}
		cout<<ans<<endl;
	}
	return 0;
}
