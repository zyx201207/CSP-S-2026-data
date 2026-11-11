#include<bits/stdc++.h>
using namespace std;
int a[100000000010];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a.begin(),a.endl(),greater());
	cout << a[m];
	return 0;
}
