#include <bits/stdc++.h>
using namespace std;
long long c,n,a,s;
int main()
{
	cin >> c >> n;
	while(n--)
	{
		cin >> a >> s;
		if(s<=2)
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}
	return 0;
}
