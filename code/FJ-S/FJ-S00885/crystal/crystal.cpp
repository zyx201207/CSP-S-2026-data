#include<bits/stdc++.h>
using namespace std;
int ans;
long long x,y;
long long n,m,i;
long long a[500005];
long long sum[500005];
queue <int> dp;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ans=0;
	a[0]=0;
	sum[0]=0;
	cin>>n>>m;
	//dp.push(1);
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		dp.push(i);
		x=a[i]*int(dp.size())-(sum[i]-sum[dp.front()-1]);
		//cout<<a[i]<<" "<<int(dp.size())<<" "<<sum[i]<<" "<<sum[dp.front()-1]<<endl;
		//cout<<x;
		while(x>m)
		{
			if(!dp.empty()) dp.pop();
			x=a[i]*dp.size()-(sum[i]-sum[dp.front()-1]);
		}
		ans=max(ans,int(dp.size()));
	}
	cout<<ans;
	return 0;
}
