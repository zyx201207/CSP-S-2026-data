#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		vector<int>ans(m+1);
		for(int p=1;p<=n;p++)
		{
			stack<int>st;
			vector<bool>cnt(n+1,false);
			for(int i=p;i<=n;i++)
			{
				if(!cnt[a[i]])
				{
					cnt[a[i]]=1;
					st.push(a[i]);
				}
				else
				{
					while(st.top()!=a[i])
					{
						int k=st.top();
						st.pop(),cnt[k]=0;
					}
				}
			}
			for(int j=1;j<=m;j++)
				ans[j]+=cnt[j];
		}
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<' ';
	}
	else
	{
		bool pd=true;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]<a[i-1])pd=false;
		}
		if(pd)
		{
			vector<bool>cnt(m+1);
			vector<int>ans(m+1);
			for(int i=1;i<=n;i++)
			{
				if(!cnt[a[i]])
					ans[a[i]]=n-i+1,cnt[a[i]]=true;
			}
			for(int i=1;i<=m;i++)
				cout<<ans[i]<<' ';
		}
		else
		{
			for(int i=1;i<=m;i++)
				cout<<'0 ';
		}
	}
	return 0;
}