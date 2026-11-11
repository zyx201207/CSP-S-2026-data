#include<iostream>
using namespace std;
long long c,T,n,d,p[2000001],dp[2000001],fn[2000001];
void work()
{
	long long ans=0;
	cin>>n>>d;
	for(int z=1;z<=n;z++)
	  cin>>p[z];
	for(int z=1;z<=n;z++)
	{
		long long l=z,cnt1=0,cnt2=1;
		fn[z]=dp[z]=1;
		for(int y=z+1;y<=n;y++)
		{
			while(p[y]-p[l]>d)
			{
				if(dp[l]==dp[y-1])
				  cnt2-=fn[l];
				else
				  cnt1-=fn[l];
				l++;
			}
			if(l==y)
			  break;
			dp[y]=dp[l]+1;
			if(dp[l]==dp[y-1])
			{
				cnt1=cnt2;
				cnt2=0;
			}
			fn[y]=cnt1;
			cnt2+=fn[y];
			if(fn[y]==2)
			  ans++;
		}
	}
	cout<<ans<<"\n";
}
void work2()
{
	cin>>n>>d;
	for(int z=1;z<=n;z++)
	  cin>>p[z];
	if(n==1||d/(p[2]-p[1])<2)
	{
		cout<<"0\n";
		return;
	}
	cout<<max(0ll,n-d/(p[2]-p[1])*2+1)<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	if(c==11||c==12)
	  for(int z=1;z<=T;z++)
		work2();
	else
	  for(int z=1;z<=T;z++)
		work();
	return 0;
}
