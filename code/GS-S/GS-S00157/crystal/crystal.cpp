#include<bits/stdc++.h>
using namespace std;
long long n,m,minn,minn_n,dm;
const long long MAXN = 1e12;
long long a[MAXN],ans,b[MAXN];
//int n,m,minn,minn_n,dm;
//const int MAXN = 1e4;
//int a[MAXN],ans=1,b[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	dm = m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=a[1];
	int r=a[n];
	int mid = (l+r)/2;
	for(int i=1;i<=n;i++)
	{
		if(abs(a[i]-mid) <abs(minn-mid))
		{
			minn = a[i];
			minn_n = i;
		}
	}
	for(int i=minn_n+1;i<=n;i++)
	{
		if(a[i]==minn)
		{
			ans++;
		}
	}
	for(int i=1;i<minn_n;i++)
	{
		dm -= abs(minn-b[i]);
		ans++;
		if(dm<=0)
		{
			break;
		}
		
	}
	
	cout<<ans;
	return 0;
}
