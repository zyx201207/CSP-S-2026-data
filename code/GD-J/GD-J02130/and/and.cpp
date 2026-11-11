#include<bits/stdc++.h>
using namespace std;
int n,m,ma = -1,nu;
long long a[100000],b[100000],ans[1000000],anser;
struct num
{
	int leth;
	int tw[11000];
	int number;
}s[11000];
int cmp(num a,num b)
{
	if(a.leth==b.leth)
		return 0;
	return a.leth<b.leth;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i] = a[i];
	}
	if(m==1)
	{
		long long ss = -1;
		for(int i=1;i<=n;i++)
		{
			ss = max(a[i],ss);
		}
		cout<<ss;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int x = 1;
		while(a[i])
		{
			s[i].tw[x++] = (a[i]%2)+1;
			if(a[i]%2!=0)
				a[i]--;
			a[i] = a[i]/2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x = 1;
		while(1)
		{
			if(s[i].tw[x]!=0)
				x++;
			else
			{
				s[i].leth = x; 
				break;
			}
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=s[1].leth;i++)
	{
		ans[i] = s[1].tw[i];
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=s[i].leth;j++)
		{
			if(ans[j] == s[i].tw[j]&&ans[j]==1)
				continue;
			else
				ans[j] = 0;
		}
	}
	for(int i=1;i<=s[1].leth;i++)
		anser = anser+(ans[i]*(2^i));
	cout<<anser;
	return 0;
}
