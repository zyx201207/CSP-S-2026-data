#include<bits/stdc++.h>
using namespace std;
int a[1000005],m,sum = 0;
long long n;
int main()
{
	freopen("and.in","r",stdin)
	freopen("and.out","w",stdout)	
	cin >> m;
	int k;
	cin >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n % 2 == 0)
	{
		sum++;
	}
	else cout << sum;
	cout << 0;
	return 0;
}
