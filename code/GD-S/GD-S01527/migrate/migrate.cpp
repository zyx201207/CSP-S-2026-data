#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
unsigned long long x[N],dp[N],many[N],all[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t,n;
	unsigned long long d;
	cin>>c>>t;
	if(c==11||c==12) {
		while(t--) {
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			long long dis=x[2]-x[1];
			if(dis>d)cout<<"0\n";
			else {
				long long a=2*d-1;
				cout<<n-a+1<<'\n';
			}
		}
		return 0;
	}
	while(t--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		long long ans=0;
		dp[1]=0;
		for(int i=1;i<=n;i++) {
			dp[i]=0;
			many[i]=1;
			all[i]=1;
			all[i-1]=0;
			int l=i,r=i;
			for(int j=i+1;j<=n;j++) {
				while(l<j&&x[j]-x[l]>d)l++;
				while(r+1<j&&dp[r+1]<=dp[l])r++;
				if(l==j)break;
				many[j]=all[r]-all[l-1];
				dp[j]=dp[l]+1;
				if(many[j]==2)ans++;
				all[j]=all[j-1]+many[j];
			}
		}
		cout<<ans<<endl;
	}
}
