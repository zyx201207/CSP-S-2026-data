#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],s[5000005],p=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--)
	{
		long long ans=0,o=1;
		for(int j=i;j>=1;j--)
		{
			s[j]=a[i]-a[j];
		}
		sort(s+1,s+i+1);
		while(ans<=m)
		{
			ans+=s[o];
			o++;
		}
		if(ans==m)
		{
			p=max(p,o);
		}
		else
		{
			p=max(p,o-1);
		}
	}
	cout<<p-1;
}
