#include<Bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(a[1] > a[2])
	{
		cout << a[2];
	}
	else 
	{
		cout << a[1];
	}
	return 0;
}
