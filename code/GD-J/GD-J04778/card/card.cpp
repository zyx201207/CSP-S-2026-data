#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int>ans(m+1,0);
	for(int k=1;k<=n;k++)
	{
		vector<bool>c(m+1, 0);
		stack<int>s;
		for(int i=k;i<=n;i++)
		{
			if(c[a[i]])
			{
				while(!s.empty())
				{
					int x = s.top();
					if(x == a[i]) break;
					c[x] = 0;
					s.pop();
				}
			}
			else
			{
				c[a[i]] = 1;
				s.push(a[i]);
			}
		}
		
		for(int i=1;i<=m;i++)
		{
			if(c[i]) ans[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
