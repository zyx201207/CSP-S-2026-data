#include<bits/stdc++.h>
using namespace std;
 
long long n,m,a[500005],s[500005],ans[500005];

bool cmp(long long x,long long y)
{
	return x<y;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	
	s[0]=0;
	long long pos=0;
	for(long long i=1;i<n;i++)
	{
		s[i]=(a[i]-a[i-1])*(i-pos)+s[i-1];
		if(s[i]>m)
		{
			while(s[i]>m)
			{
				s[i]-=(a[i]-a[pos]);
				pos++;
			}
		}
		ans[i]=i-pos+1;
	}
	long long maxn=0;
	for(long long i=1;i<=n;i++)
	{
		maxn=max(maxn,ans[i]);
	}
	cout<<maxn;
	
	return 0;	
} 
