#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500003],minn=1e18+10;
vector<long long>p[500003];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			long long x=a[i]-a[j];
			p[i].push_back(x);
			if(x<minn)minn=x;
		}
	}
	if(minn>m)
	{
		printf("%d",0);
		return 0;
	}
	if(minn==m)
	{
		printf("%d",1);
		return 0;
	}
	long long best=-1;
	for(int i=1;i<=n;i++)
	{
		long long cnt=0,mm=m;
		for(int j=0;j<p[i].size();j++)
		{
			if(mm>=p[i][j])
			{
				mm-=p[i][j],cnt++;
			}
			else break;
		}
		if(cnt>best)best=cnt+1;
	}
	printf("%lld",best);
	return 0;
}
