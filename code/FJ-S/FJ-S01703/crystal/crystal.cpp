#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long m,a[N],b[N],c[N],s[N];
long long n;
long long check(int x,int y)
{
	long long ans=0;
	for(int i=x;i<y;i++)
	{
		ans=ans+c[i]*(b[y]-b[i]);
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}	
	sort(a+1,a+1+n);
	long long cnt=0;
	long long maxx=0;
	for(int i=1;i<=n;i++) 
	{
		if(i==1||a[i]!=a[i-1])
		{
			b[++cnt]=a[i];
		}
		c[cnt]++;
	} 
	for(int i=1;i<=cnt;i++) maxx=max(maxx,c[i]);
	s[1]=c[1];
	for(int i=2;i<=cnt;i++)
	{
		int l=1,r=i;
		s[i]=s[i-1]+c[i];
		while(l+1<r)
		{
			int mid=(r-l)/2+l;
			long long q=check(mid,i);
			if(q<=m) 
			{
				maxx=max(maxx,s[i]-s[mid-1]+min((m-q)/(b[i]-b[mid-1]),c[mid-1]));
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	maxx=max(maxx,c[2]+min(c[1],m/(b[2]-b[1])));
	cout<<maxx;
	return 0;
}
