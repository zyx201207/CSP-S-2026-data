#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 500;
int a[N]={}; bool p[N]={};
int max1 = -1; int n,m;
void dfs(int k,int s)
{
	if (k == m) 
	{
		max1 = max(max1,s);
		return ;
	}
	for (int i = 1;i <= n;i++)
	{
		if (s == 0) 
		{
			p[i] = 1; 
			dfs(k++,a[i]);
		} 
		else
		{
			if (!p[i])
			{
				long long num = s & a[i];
				p[i] = 1;
				dfs(k++,num);
			}
		}
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	cin >> a[i];
	dfs(0,0);
	cout << max1;
	return 0;
}
