#include <bits/stdc++.h>
#define O 2000005
using namespace std;
int c,t,n,d;
int lst[O];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i = 1;i <= t;++i)
	{
		cin >> n >> d;
		for(int k = 1;k <= n;++k)
			scanf("%d",&lst[i]);
		int cha = lst[2] - lst[1];
		if(cha < 2 * d)	//没有选择空间,只能一座一座跳 
		{
			cout << 0 << endl;
		}
		else
		{
			int ans = d / cha + 1;
			cout << ans << endl;
		}
	}
}
/*
看等差数列的数据 
*/
