#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
bool cmp(long long x, long long x2)
{
	return x>x2;
}
long long chaz(long long qis, long long zong)//qishi,zongshu
{
	long long heng=a[qis],jis=0;
	for(long long i=qis+1;i<=n && zong>=0;i++)
	{
		if(heng-a[i]<=zong)
		{
			jis++;
			zong-=heng-a[i];
		}
	}
	return jis+1;
}
int main()
{
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++)
	{
		ans=max(ans,chaz(i,m));
	}
	cout<<ans<<endl;
	return 0;
} 
