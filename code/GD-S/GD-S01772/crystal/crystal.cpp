#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],sum=0;
map<long long,int> bz;
long long maxx=-1e18,lst;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		bz[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum+=a[n]-a[i];
		long long d=bz[a[i]];
		maxx=max(maxx,d);
	}
	if(sum<=m)
	{
		cout<<n;
		return 0;
	}
	lst=a[n];
	for(int i=n-bz[lst];i>=1;i--)
	{
		long long p=lst-a[i];
		if(sum-p*i<=m)
		{
			cout<<i;
			return 0;
		}
		else
		{
			sum-=p*i;
			lst=a[i];
		}
		cout<<lst<<" "<<bz[lst]<<" "<<p<<" "<<i<<endl;
		i-=bz[lst];
		i++;
	}
	cout<<maxx;
	return 0;
}
