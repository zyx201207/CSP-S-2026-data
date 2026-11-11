#include<bits/stdc++.h>
using namespace std;
int n,d=-1;
long long l,m,a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int p=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=p)
		{
			p=-1;
			break;
		}
	}
	if(p!=-1)
	{
		for(int i=1;i<=n;i++)
		{
			if (l*p>=m)
			{
				cout<<i;
				return 0; 
			}
			l+=i;
		}
		cout<<n;
		return 0;
	}
	int pp=2;
	for(int i=1;i<=n;i++)//×ó 
	{
		for(int j=pp;j<=n;j++)//ÓÒ 
		{
			l+=(a[j]-a[j-1])*(j-i);
			if(l>m)
			{
				pp=j-1;
				d=max(d,j-i);
				break;
			}		
		}
		l-=a[pp]-a[i];
	}
	cout<<d;
	return 0;
	
}
