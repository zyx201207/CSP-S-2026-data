#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		int a[10010];
		for(int i = 1 ; i <= n ; i ++) cin >> a[i];
		int cnt = 0;
		for(int i = 1 ; i <= n ; i ++)
		for(int j = i+1 ; j <= n ; j ++)
		{
			int num = a[j] - a[i];
			if(num ==2*d-1) if((j-i)*d > a[j]-a[i]) cnt ++;
		}
		cout << cnt << "\n";
	}
}
