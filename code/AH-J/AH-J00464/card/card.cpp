#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[20005];
bool f[20005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)	cin >> a[i];
	s[1] = a[1];
	f[a[1]] = 1;
	for(int i = 2;i <= n;i++)
	{
		if(f[a[i]] == 1)	
		{
			
		}
	}
	return 0;
}

