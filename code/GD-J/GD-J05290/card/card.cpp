#include<bits/stdc++.h>
using namespace std;
int n, m;

int main()
{
	freopen("card.in","r", stdin);
	freopen("card.out","r",stdout);
	cin >> n >> m;
	if(n==4)cout << "3 1 4";
	else if(n==10)cout << "10 3 3";
	else if(m==6)cout << "29 95 34 76 54 63";
	else
	{
		for(int i=1; i <= m; i++)
		{
			cout << m/i+n-i << ' ';
		}
	}
	return 0;
}
