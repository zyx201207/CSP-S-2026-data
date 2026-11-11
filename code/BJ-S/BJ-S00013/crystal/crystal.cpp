#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int ans[500005];
int main()
{
	freopen("crystal.in", "r",stdin);
	freopen("crystal.out","w",stdout);
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			ans[i]=max(abs(a[i]-a[j]), ans[i]);
		}
	}
	int index=1;
	for(int i=2;i<=n;i++)
	{
		if(ans[index]>ans[i])
		{
			index=i;
		}
	}
	int i=1;
	while(m>0)
	{
		i++;
		int jndex=1;
		for(int i=2;i<=n;i++)
		{
			if(i==index||a[i]==a[index])
			    continue;
			if(abs(a[index]-a[jndex])>abs(a[index]-a[i]))
			{
				jndex=i;
			}
		}
		if(m-abs(a[index]-a[jndex])>=0)
		{
			m-=abs(a[index]-a[jndex]);
			a[jndex]+=abs(a[index]-a[jndex]);
		}
		else
		{
			break;
		}
	}
	sort(a+1, a+n+1);
	int now=a[1];
	int cnt=1;
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(now!=a[i])
		{
			ans=max(ans, cnt);
			cnt=1;
			now=a[i];
		}
		else
		{
			cnt++;
		}
	}
	cout<<ans;
	return 0;
}
