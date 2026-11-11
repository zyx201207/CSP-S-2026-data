#include<bits/stdc++.h>
using namespace std;
long long a[500005];
map<long long,long long> mp;
long long n;
long long m,sum;
void dfs(long long i)
{
	if(i>m) return;
	for(long long iu=1;iu<=n;iu++)
	{
		mp[a[iu]]--;
		mp[a[iu]+1]++;
		sum=max(sum,mp[a[iu]+1]);
		a[iu]++;
		dfs(i+1);
		a[iu]--;
		mp[a[iu]+1]--;
		mp[a[iu]]++;
	}
}
long long dcsl(long long cha)
{
	long long op=1,iop=m;
	while(op*cha<=iop)
	{
		iop-=op*cha;
		op++;
	}
	return op;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5&&m<=10)
	{
		for(long long j=1;j<=n;j++)
		{
			cin>>a[j];
			mp[a[j]]++;
		}
		dfs(1);
		cout<<sum;
		return 0;
	}
	long long cha=0x3f3f3f3f;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>=2) cha=min(cha,a[i]-a[i-1]);
	}
	cout<<dcsl(cha);
	return 0;
}
