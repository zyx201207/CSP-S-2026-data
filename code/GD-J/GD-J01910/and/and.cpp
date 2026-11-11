#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],answer=-1,maxx=-1;
int sum(int k)
{
	int ans=0;
	while(k>0)
	{
		if(k%2==1)ans++;
		k/=2;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,a[i]);
		cin>>a[i];
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				answer=max(answer,a[i]&a[j]); 
			}
		}
		cout<<answer;
		return 0;
	}
	if(n>20)
	{
		sort(a+1,a+1+n);
		answer=(1<<30)-1;
		for(int i=m;i>=1;i--)
		{
			answer&=a[i];
		}
		cout<<answer;
		return 0;
	}
	for(int i=0;i<(1<<n);i++)
	{
		if(sum(i)!=m)continue;
		int ans=(1<<n)-1;
		for(int j=1;j<=n;j++)
		{
			if(i&(1<<(j-1)))
			{
				ans&=a[j];
			}
		}
		answer=max(answer,ans);
	}
	cout<<answer;
	
	return 0;
}
