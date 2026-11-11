#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[501],b[501];
int used[501],ans;
stack <int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			while(!s.empty())
				s.pop();
			for(int k=1;k<=n;k++)
			{
				used[k]=0;
			}
			for(int k=j;k<=n;k++)
			{
				if(used[a[k]]==0)
				{
					s.push(k);
					used[a[k]]=min(used[a[k]],k);
				}
				else
				{
					while(s.top()!=used[a[k]])
					{
						s.pop();
					}
				}
			}
			while(!s.empty())
			{
				if(s.top()==i)
				{
					ans++;
					break;
				}
				s.pop();
			}
		}
		cout<<ans<<' ';
	}
	return 0;
}
