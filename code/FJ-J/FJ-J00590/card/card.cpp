#include<iostream>
using namespace std;
const int maxn1 = 5e5+10;
const int maxn2 = 3e5+10;

int n,m;
int ans[maxn2],c[maxn2],q[maxn1];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> q[i];
		c[q[i]] = i;
	}
	for(int i = 1;i<=n;i++)
	{
		int k = i;
		while(k<=n)
		{
			ans[q[k]]++;
			if(k == n) break;
			k = c[q[k]]+1;
		}
	}
	
	for(int i = 1;i<=m;i++) cout << ans[i] << " ";
	return 0;
}
