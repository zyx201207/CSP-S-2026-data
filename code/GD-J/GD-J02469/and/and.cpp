#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans,a[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	if(m==1)	ans=a[1];
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)	continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else
	{
		for(int i=1;i<=30;i++)	ans=ans*2+1;
		for(int i=1;i<=m;i++)	ans&=a[i];		
	}
	cout<<ans;
	return 0;
} 
