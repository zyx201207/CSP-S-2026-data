#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,ans;
long long x[N],p[N],dp[N],dp2[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		long long c=x[2]-x[1];
		if(c>d){
			cout<<"0\n";
			continue;
		}
		long long j=1,ans=0;
		for(int i=1;i<=n;i++){
			while(x[i]+d>=x[j]&&j-1<=i)j++;
			p[i]=j;
		}
		for(int i=n;i>=1;i--){
			ans+=dp[p[i]];
			dp[i]=dp[p[i]];
			if(p[i-1]!=i)dp[i]+=p[i-1]-i;
		}//อ๊มห ผูต๔มห w_w 
		cout<<ans/2<<"\n";
	}
	return 0;
}

