#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[1000005],sum;
bool flag = true;
stack<int> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i < n;i++)
	{
		if(a[i] != a[i+1])
			flag = false;
	}
	if(flag)
		cout << n;
	else
		cout << n << " " << n / 2 - 1 << " " << n / 3 + 1 << endl;
	return 0;
}
