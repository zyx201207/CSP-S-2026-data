#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 2e5 + 5;
int n , m , a[N] , ans[N] , k[N] , b[N] , v = 1;
int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i];
	for(int i = 1 ; i <= n ; i ++)
	{
		v = 1;
		memset(k , 0 , sizeof(k));
		memset(b , 0 , sizeof(b));
		for(int j = i ; j <= n ; j ++)
		{
			if(k[a[j]] == 0)
			{
				b[v] = a[j];
				k[a[j]] = v;
			}
			else
			{
				for(int z = k[a[j]] + 1 ; z <= v ; z ++)
				{
					k[b[z]] = 0;
				}
				v = k[a[j]];
			}
			v ++;
		}
		for(int j = 1 ; j < v ; j ++) ans[b[j]] ++;
	}
	for(int i = 1 ; i <= m ; i ++) cout << ans[i] << " ";
	return 0;
}
