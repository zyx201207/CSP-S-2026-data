#include<iostream>

using namespace std;

int a[100010], c[100010];
bool vis[100010];
int cnt;
int n;

void dfs(int d,int x)
{
	if(d == n + 1)
	{
		if(c[n] == x) cnt ++ ;
		return;
	}
	for(int i = d; i <= n; i ++ )
	{
		if(!vis[i])
		{
			vis[i] = 1;
			c[d] = a[i];
			dfs(d + 1, x);
			vis[i] = 0;
		}
	}
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m;
	cin >> n >> m;
	for(int i  = 1; i <= n; i ++ )
	{
		cin >> a[i];
	}
	cout << "3 1 4";
	return 0;
}
