#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	else if(m==2)
	{
		int cnt=1,i=n-1;
		while(a[i]==a[i+1])
		{
			i--;
			cnt++;
		}
		ans[a[n]]=n;
		ans[a[i]]=n-cnt;
	}
	else if(n<=500)
	{
		for(int i=1;i<=n;i++)
		{
			queue<int> q1,q2;
			for(int j=i;j<=n;j++)
			{
				while(!q1.empty())
				{
					if(a[q1.front()]==a[j])
					{
						while(!q2.empty())
							q2.pop();
					}
					else	q2.push(q1.front());
					q1.pop();
				}
				q1.push(j);
				while(!q2.empty())
				{
					q1.push(q2.front());
					q2.pop();
				}
			}
			while(!q1.empty())
			{
				ans[a[q1.front()]]++;
				q1.pop();
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i-1])	ans[a[i]]++;
			else	ans[a[i]]=ans[a[i-1]]+1;
		}
	}
	for(int i=1;i<=m;i++)	cout<<ans[i]<<" ";
	return 0;
}
