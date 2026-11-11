#include <bits/stdc++.h>
using namespace std;
int main()
{
	string n , n1 , n2 , n3;
	cin >> n >> n1 >> n2 >> n3;
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	if (n[0] == n2[0] && n[1] == n2[1]) cout << '1';
	else 
	{
		cout << "0000";
		return 0;
	}
	if(n1[0] == n3[0] && n1[1] == n3[1]) cout << '1';
	else
	{
		cout << "000";
		return 0;
	}
	if((n1[2] <= 'C' && n3[2] <= 'C') || (n1[2] >= 'D' && n3[2] >= 'D')) cout << '1';
	else
	{
		cout << "00";
		return 0;
	}
	if(max(n1[2] , n3[2]) - min(n1[2] , n3[2]) == 1) cout << '1';
	else cout << '0';
	return 0;
}
