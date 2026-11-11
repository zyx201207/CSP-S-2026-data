#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	char q3,w3;
	int q1,w1,q2,w2; 
	cin >> q1 >> q2 >> q3 >> w1 >> w2 >> w3;
	if(q1==w1)
		cout << 1;
	else
	{
		cout << "0000";
		return 0;
	}
	if(q2==w2)
		cout << 1;
	else
	{
		cout << "000";
		return 0;
	}
	if((q3<='C'&&w3<='C')||(q3>='D'&&w3>='D'))
		cout << 1;
	else
	{
		cout << "00";
		return 0;
	}
	if(char(q3+1)==w3||char(q3-1)==w3)
		cout << 1;
	else
	{
		cout << 0;
		return 0;
	}
	return 0;
}
