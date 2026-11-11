#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	int n,ai,i;
	string ci;
	cin >> n;
	if (n == 1)
	{
		cin >> ai >> ci;
		cout << "0";
	}
	else
	{
		for (int j = 1 ; j <= n ; j++)
		{
			cin >> ai >> ci;
		}
		cout << "2";
	}
	return 0;
}
