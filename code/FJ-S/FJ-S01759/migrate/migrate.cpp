#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,l,r,minn,sum;
int n,lj[2000005],dp[2000005];
ll a[2000005],d;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {

		cin>>n>>d;
		sum=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int z=1; z<=n; z++) {
			for(int i=1;i<=n;i++)
			{
				dp[i]=0;
				lj[i]=0;
			}
			dp[z]=1;
			for(int i=z+1; i<=n; i++) {
				lj[i]=lj[i-1]+1;
				for(int j=i-1; j>=1; j--) {
					if(a[i]-a[j]>d)	break;
					if(lj[j]+1<lj[i]) {
						dp[i]=dp[j];
						lj[i]=lj[j]+1;
					} else if(lj[j]+1==lj[i])	dp[i]+=dp[j];
				}
			}
			for(int i=1; i<=n; i++)
			{
				if(dp[i]==2)	sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
	我肯定没有打错freopen吧darling。
*/
/*
	不对！不是6：00比赛结束吗？怎么是六点半，害我白高兴一场
*/ 
/*
	这一生，太漫长却止步咫尺天涯间，谁仍记，那落花流水世界 
