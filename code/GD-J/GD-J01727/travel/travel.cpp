#include <bits/stdc++.h>
using namespace std;

int arr[19][6], ans[4], fi = 0;
string s[2][2], a2 = "", b2 = "";
char a3, b3;
int main ()
{
	
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0;  j< 2; j++)
		{
			cin>> s[i][j];
		}
	}
	if (s[0][0] == s[1][0]) 
	{
		ans[fi] = 1, fi++;
		for (int i = 0; i < 2; i++)
		{
			a2 += s[0][1][i];
			b2 += s[1][1][i];
		}//pai
		if (a2 == b2) ans[fi] = 1, fi++;
		else
		{
			cout <<"1000";
			return 0;
		}
		a3 = s[0][1][2], b3 = s[1][1][2];//zuowei
		if ((a3 - 'A' >= 3 && b3 - 'A' >= 3) || (a3 - 'A' <= 2 && b3 - 'A' <= 2)) ans[fi] = 1, fi++;
		else 
		{
			cout << "1100";
			return 0;
		}
		if (a3 - 'A' >= 4 && b3 - 'A' >= 4) ans[fi] = 1;
		else if ((a3-'A') - (b3-'A') == 1||(a3-'A') - (b3-'A') == -1) ans[fi] = 1;
		else ans[fi] = 0;
	}//chexiang
	else
	{
		cout << "0000";
		return 0;
	}
	cout << s[0][0] << " " << s[1][0] << endl;//
	cout << a2 << " " << b2 << endl;//
	cout << a3 << " " << b3 << endl;//
	for (int i = 0; i < 4; i++)
	{
		cout << ans[i]; 
	}
	return 0;
}
