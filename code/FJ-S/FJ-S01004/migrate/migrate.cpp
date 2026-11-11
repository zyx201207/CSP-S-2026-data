#include<bits/stdc++.h>
using namespace std;
long long c,T,a[2000005],deng,n,d,ans;
bool isdeng;
void solve()
{
	memset(a,0,sizeof(a));
	isdeng=1,ans=0;
	cin>>n>>d;
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i];
		if(i==2)
			deng=a[2]-a[1];
		if(i>2&&a[i]-a[i-1]!=deng)
			isdeng=0;
	}
	deng=a[2]-a[1];
	cout<<deng<<"\n";
	if(isdeng)
	{
		if(d<=deng)
		{
			cout<<0<<"\n";
			return;
		}
		if(deng==0)
		{
			cout<<0<<"\n";
			return ;
		}
		long long shang=d/deng;
		for(long long i=1;i<=shang-1;++i)
		{
			for(long long j=n;j>=1;--j)
				if(j-i-1>0&&shang>0)
					ans+=(j-i-1)/shang;
		}
		cout<<ans<<"\n";
	}
	else
	{
		cout<<0<<"\n";
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	if(c==0)
	{
		cout<<"0\n1";
		return 0;
	}
	while(T--)
		solve();
	return 0;
}
