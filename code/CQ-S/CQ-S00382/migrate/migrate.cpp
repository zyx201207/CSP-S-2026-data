#include <bits/stdc++.h>
using namespace std;
const long long N=2e6+5,inf=2e18;
long long c,t,n,d,x[N];
struct node{
	long long c,s;
}dp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int cnt=0;
		if(c==11 || c==12){
			for(int i=1;i<=n;i++) dp[i]={inf,0};
			dp[1]={0,1};
			for(int i=1;i<=n;i++){
				int z=i-1;
				while(z>=1 && x[i]-x[z]<=d){
					if(dp[z].c+1<dp[i].c){
						dp[i]={dp[z].c+1,dp[z].s};
					}
					else if(dp[z].c+1==dp[i].c){
						dp[i].s+=dp[z].s;
					}
					z--;
				}
				if(dp[i].s==2){
					cnt+=(n-i+1);
				}
			}
			cout<<cnt<<"\n";
			continue;
		}
		if(c==13 || c==14){
			long long r=x[1]+d,l=x[n]-d;
			for(int i=1;i<=n;i++){
				long long l1=(long long)(lower_bound(x+1,x+1+n,x[i]+d)-x),l2=(long long)(lower_bound(x+1,x+1+n,x[i]+2*d)-x);
				cnt+=max(0ll,min(n,l2-1)-l1);
			}
			cout<<cnt<<"\n";
			continue;
		}
		for(int w=1;w<=n;w++){
			for(int i=w;i<=n;i++) dp[i]={inf,0};
			dp[w]={0,1};
			for(int i=w;i<=n;i++){
				int z=i-1;
				while(z>=w && x[i]-x[z]<=d){
					if(dp[z].c+1<dp[i].c){
						dp[i]={dp[z].c+1,dp[z].s};
					}
					else if(dp[z].c+1==dp[i].c){
						dp[i].s+=dp[z].s;
					}
					z--;
				}
				if(dp[i].s==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
