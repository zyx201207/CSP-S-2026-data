#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500005],b[500005],c[500005];
bool f[500005];
vector<long long> t;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	
	for (int i = 1;i <= n;i ++)
	{
		memset(f,0,sizeof(f));
		for (int j = i;j <= n;j ++)
		{
			if (!f[a[j]])
			{
				c[a[j]] ++;
				f[a[j]] = true;
			}
			
		}
	}
	
	for (int i = 1;i <= m;i ++) cout << c[i] << " ";
	
	return 0;
}
