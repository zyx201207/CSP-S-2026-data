#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010],b[100010],s[100010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	int tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s[i]=min(a[i],b[i+1]);
	}
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>maxx)
		{
			maxx=s[i];
		}
	}
	cout<<maxx;
	return 0;
}
