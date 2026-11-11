//csps+=rp++
#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,maxx;
long long d[500005],a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	int bm=m;
	sort(a+1,a+n+1);
	 d[1]=1;
	for(int i=2;i<=n;i++)
	{
		long long x=max(abs(a[i]),abs(a[i-1]));
		long long y=min(abs(a[i]),abs(a[i-1]));
		if(m-d[i-1]*(x-y)>=0)
		{
			m-=d[i-1]*(x-y);
			++ans;
			d[i]=ans;
			maxx=max(d[i],maxx);
		}
		else{
			m=bm;
			ans=1;
			d[i]=1;
		}
	}
	cout<<maxx;
} 
/*
5 5
1 2 4 8 9


*/
/*
#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,maxx;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int sum=m;
		for(int j=1;j<=i;j++)
		{
			if(sum>=a[i]-a[j])
			{
				sum-=a[i]-a[j];
				ans++;
			}
		} 
		maxx=max(ans,maxx);
		ans=0;
	}
	cout<<maxx;
	
	
	return 0;
}
*/
