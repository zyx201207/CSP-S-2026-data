#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] >> c[i];
		//cout << 111;
	}
	//cout << 111;
	long long l = 1 , r = n , cnt = 0;
	while(l < r)
	{
		//cout << a[l] << ' ' << a[r] << endl;
		//cout << cnt << endl;
		//cout << 111;
		if(a[l] <= 0)l ++;
		if(a[r] <= 0) r --;
		//
		long long minn = min(a[l] , a[r]);
		if(c[l] != c[r])
		{
			cnt += minn;
			a[l] -= minn;
			a[r] -= minn;
		}
		else
		{
			a[l] -= minn;
			a[r] -= minn;
		}
	}
	cout << cnt;
	return 0;
}
/*
3
2 a
2 b
1 c
*/
