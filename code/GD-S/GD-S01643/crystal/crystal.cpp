#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
long long n,m;
long long a[500000],b[500000];
int ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	long long x=0,y1=0,y2=1;
	for(y1=0;y1<n;y1++)
	{
		if(x>=m) break;
		x=x+ans*b[y1];
		ans++;
	}
	y1++;
	if(ans==n)
	{
		cout<<ans;
	}
	else
	{
		for(;y1<n;y1++)
		{
			x=0;y2=1;
			for(int i=y1-1;i>=0;i--)
			{
				if(x>=m) break;
				x=x*y2+b[i];
				y2++;
			}
			if(ans<y2) ans=y2;		
		}
		cout<<ans;
	}
	return 0;
}
