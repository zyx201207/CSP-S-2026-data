#include<bits/stdc++.h>
#define ll long long
#define ull long long
using namespace std;
int n, m, a[500010];
int s[300010];
bool v[300010];
stack<int> q;
void solve()
{
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		while(!q.empty()) q.pop();
		for(int j = i;j <= n;j++)
		{
			if(v[a[j]] == 0) 
			{
				q.push(a[j]);
				v[a[j]] = 1;
			}
			else
			{
				while(!q.empty() && q.top() != a[j])
				{
					v[q.top()] = 0;
					q.pop();
				}
			}
		}
		for(int j = 1;j <= m;j++)
		{
			if(v[j] != 0) s[j]++;
			v[j] = 0;
		}
	}
	for(int i = 1;i < m;i++)
	{
		cout<<s[i]<<" ";
	}
	cout<<s[m];
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}

