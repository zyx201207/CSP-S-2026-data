#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 != s3)
	{
		cout << "0000";
		return 0;
	}
	cout << 1;
	if(s2[0] != s4[0] || s2[1] != s4[1])
	{
		cout << "000";
		return 0;
	}
	cout << 1;
	if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
	{
		if(s4[2] == 'D' || s4[2] == 'F')
		{
			cout << "00";
			return 0;
		}
	}
	else
	{
		if(s4[2] == 'A' || s4[2] == 'B' || s4[2] == 'C')
		{
			cout << "00";
			return 0;
		}
	}
	cout << 1;
	if(abs(s2[2] - s4[2]) == 1) cout << 1;
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
