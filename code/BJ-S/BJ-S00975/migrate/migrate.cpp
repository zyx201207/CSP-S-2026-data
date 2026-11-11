#include<bits/stdc++.h>
using namespace std;

const int MXN = 2e6+3 ;
const long long INF = 2e18 ;

long long d,x[MXN],res;
int c,t,n,dp[MXN],dis[MXN],sd[MXN];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		res=0;
		for(int i=1;i<=n;i++){
			dis[i]=sd[i-1]=0;
			dp[i]=sd[i]=1;
			int l=i,r=i;
			for(int j=i+1;j<=n;j++){
				while(x[l]<x[j]-d)
					l++;
				r=max(l-1,r);
				while(r<j-1&&dis[r+1]<=dis[l])
					r++;
				dis[j]=dis[l]+1;
				dp[j]=sd[r]-sd[l-1];
				sd[j]=sd[j-1]+dp[j];
				if(dp[j]==2)
					res++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}