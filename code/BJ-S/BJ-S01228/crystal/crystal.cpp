#include<bits/stdc++.h>
using namespace std;
long long a[600010],b[600010],l=0;
long long n,m,maxx=0;
int ch()
{
	long long c=2;
	long long d=a[2]-a[1];
	while(c<=n-1)
	{
		if(a[c+1]-a[c]!=d) return 0;
		c++;
	}
	return d;
}
long long ck()
{
	long long cnt=0,aa=1;
	while(true)
	{
		if(m<cnt||aa>=n) return aa;
		aa++,cnt=l*(aa+1)*aa/2;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		//b[i]=b[i-1]+a[i];
		//maxx=max(maxx,abs(a[i]));
	}
	sort(a+1,a+n+1);
	int f=ch();
	if(f!=0)
	{
		l=f;
		//cout<<l;
		cout<<ck();
		return 0;
	}
	else
	{
		
	
	long long ans1=0,ans=0;
	long long nn=m;// cout<<ans;
	for(int i=n;i>=1;i--)
	{
		m=nn;
	//	cout<<i<<" "<<ans<<endl;
		int p=i-1;
		while(m!=0)
		{
			if(p==0)
			{
				break;
			}
			if(m<a[i]-a[p]) break;
			else ans1++,m-=a[i]-a[p],p--;
		}
		ans=max(ans,ans1);
		if(ans1==n-1) break;
		ans1=0;
	}
	cout<<ans+1;
	}
}
