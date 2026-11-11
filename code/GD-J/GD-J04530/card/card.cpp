#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],bj[3005],ans[100005];
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int fg=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) fg=1;
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			memset(bj,0,sizeof(bj));
			for(int j=i;j<=n;j++)
			{
				if(bj[a[j]])
				{
					while(!s.empty()&&s.top()!=a[j])
					{
						bj[s.top()]--;
						s.pop();
					}
				}
				else bj[a[j]]=1,s.push(a[j]);
			}
			while(!s.empty()) ans[s.top()]++,s.pop();
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		return 0;
	}
	if(fg==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i-1]) ans[a[i-1]]=i-1;
		}
		ans[a[n]]=n;
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ans[a[i]]++;
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
