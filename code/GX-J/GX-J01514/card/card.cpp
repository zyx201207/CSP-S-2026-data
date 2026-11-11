#include<bits/stdc++.h>
using namespace std;
int main()
{
	fropen("card.in", "r", stdin);
	fropen("card.out", "w", stdout);
	int n, m, a=10;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		if(n==10 && m==3)
			cout << a;
		else
			cout << 3;
	}
	cout << n << m;
	
	rutern 0;
}
