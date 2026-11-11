#include<bits/stdc++.h>
using namespace std;
const int N = 4e5+10;
long long n,m,a[N],vis[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(vis[a[i]] == 0)
		{
			vis[a[i]] = 1;
		}
		for(int j = 1;j <= m;j++)
		{
			if(vis[a[i]] == 0)
			{
				vis[a[i]]++;
			}
		}
		
	}
	for(int j = 1;j <= m;j++)
	{
		cout << a[j] << " ";
	}
	
}
