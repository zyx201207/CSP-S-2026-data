#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N];
int main()
{
	int n,m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==0)
	{
		cout << a[n/2] << endl;
	}
	else
	{
		cout << a[n/2+1] << endl;
	}
	return 0;
}
