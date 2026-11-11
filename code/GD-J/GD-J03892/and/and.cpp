#include<bits/stdc++.h>
using namespace std;
const int RHZ = 2 * 1e5 + 10;
int n , m , max_zzh , max_rhz , pr;
int a[RHZ] , zzh[RHZ];
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a , a + n);
	max_zzh = a[n - 1];
	max_rhz = a[n - 2];
	pr = max_zzh & max_rhz;
	cout << pr;
	return 0;
} 
