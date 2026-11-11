#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,l;
int n,s=1,mx;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int j=1;j<=n;j++)
	{
		if(s>=n)
		{
			cout<<n;
			return 0;
		}
		l+=s*(a[s+1]-a[s]);
		if(l>=m)
		{
			l-=s*(a[s+1]-a[s]);
			break;
		}
		s++;
	}
	mx=s;
	int p=s;
	for(int i=s+1;i<=n;i++)
	{
		l+=p*(a[i]-a[i-1]);
		p++;
		for(int j=i-p+1;j<=i;j++)
		{
			if(l<=m) break;
			l-=a[i]-a[j];
			p--;
		}
		mx=max(mx,p);
		
	}
	cout<<mx;
	return 0;
}