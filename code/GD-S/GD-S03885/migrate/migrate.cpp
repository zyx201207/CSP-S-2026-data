#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int c,Q,n,a[2000007],d; 
int dis[2000007],dp[2000007];
int sum[2000007];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>Q;
	for(int qq=1;qq<=Q;++qq){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(c<=10||c>=19){
			int cnt=0;
			for(int s=1;s<=n;++s){
				for(int i=1;i<=n;++i) dis[i]=LONG_LONG_MAX,sum[i]=dp[i]=0;
				dis[s]=0;
				for(int i=s;i<n;++i){
					int j=i+1;
					while(j<=n&&a[j]-a[i]<=d){
						dis[j]=dis[i]+1;
						j++;
					}
					if(i==j-1) break;
					i=j-2;
				}
				int l=s,lst=s+1;
				dp[s]=sum[s]=1;
				for(int i=s+1;i<=n;++i){
					while(l<i&&a[i]-a[l]>d||dis[l]<dis[i]-1) l++;
					if(dis[i]!=dis[i-1]) lst=i;
					if(l<i&&lst>l) dp[i]=sum[lst-1]-sum[l-1];
					sum[i]=sum[i-1]+dp[i];
				}
				for(int i=1;i<=n;++i) if(dp[i]==2) cnt++;
			}
			cout<<cnt<<"\n";
			continue;
		}else if(c<=18){
			int cnt=0;
			for(int i=1;i<=n;++i) dis[i]=LONG_LONG_MAX,sum[i]=dp[i]=0;
			dis[1]=0;
			for(int i=1;i<n;++i){
				int j=i+1;
				while(j<=n&&a[j]-a[i]<=d){
					dis[j]=dis[i]+1;
					j++;
				}
				if(i==j-1) break;
				i=j-2;
			}
			int l=1,lst=1+1;
			dp[1]=sum[1]=1;
			for(int i=1+1;i<=n;++i){
				while(l<i&&a[i]-a[l]>d||dis[l]<dis[i]-1) l++;
				if(dis[i]!=dis[i-1]) lst=i;
				if(l<i&&lst>l) dp[i]=sum[lst-1]-sum[l-1];
				sum[i]=sum[i-1]+dp[i];
			}
			for(int i=1;i<=n;++i){
				if(dp[i]==2) cnt+=n-i+1;
			}
			cout<<cnt<<"\n"; 
		}else{
			cout<<"0\n";
		}
	}
	return 0; 
}
