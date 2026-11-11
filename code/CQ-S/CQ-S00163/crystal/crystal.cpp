#include <bits/stdc++.h>
using namespace std;
long long n, m, x, k, sum = 0, num = 0, a[500005], b[500005];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (n % 2 == 0)
	    x = n / 2;
	else
	    x = n / 2 + 1;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= a[x])
		{
		    b[i] = a[x] - a[i];
		    k = i;
		}
	}
	sort (b + 1, b + k + 1);
	for (int i = 1; i <= x; i++)
	{
		if (sum + a[i] <= m)
		{ 
		    num++;
		    sum += a[i];
		}
		else
		    break;
	}	
	cout << num;
}
