#include<bits/stdc++.h>//贵阳市花溪区剑桥中学  李政轩   GZ-S00290 
using namespace std;
const int maxn = 1e6+325;
long long n,m,need,sum,ans,t;
long long a[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i = 1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]-a[i-1] == 1)
		{
			t++;
		}
	}
	sort(a+1,a+1+n);
	long long mid = (n+1)/2;
	long long temp = a[mid];
	if(t == n)
	{
		mid = (a[1]+a[n]+1)/2;
		temp = a[mid];
	}
	long long pos = upper_bound(a+1,a+1+n,temp)-(a+1);
	for(long long i = pos;i>=1;i--)
	{
		if(sum>=m)
		{
			break;
		}
		if(a[i]<=temp)
		{
			need = temp-(a[i]);
			ans++;
		}
		sum+=need;
	}
	cout<<ans;
	return 0;
}
