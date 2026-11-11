#include<bits/stdc++.h>
using namespace std;
#define int long long
const int PR = 2 * 1e5 + 10;
int a[PR];
char c[PR];
string zzh;
bool k = true;
int cnt;
signed main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		for(int j = 1; j <= a[i]; j++)
		{
			zzh += c[i];
		}
	}
	int l = 0 , r = zzh.size();
	while(l < r)
	{
		if(zzh[l] != zzh[r])
		{
			zzh[r] = zzh[l];
			cnt++; 
		}
		l++;
		r--;
	}
	cout << cnt;
	return 0;
}
