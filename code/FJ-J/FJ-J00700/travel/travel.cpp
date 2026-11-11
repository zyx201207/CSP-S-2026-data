#include <bits/stdc++.h>
using namespace std;
int cnt1, cnt2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
    cin >> a >> b >> c >> d;
	for(int i = 0; i <= a.length()-1; i++)
	{
		if(a[i] + '0'== c[i] + '0')
			cnt1++;
	}
	if(cnt1 == 2)
		cout << "1";
	else
	{
		cout << "0000";
		return 0;
	}
		
	for(int i = 0; i <= b.length()-1; i++)
	{
		if(b[i] + '0'== d[i] + '0')
			cnt2++;		
	}
	if(cnt2 == 2)
		cout << "1";
	else
	{
		cout << "000";
		return 0;
	}
	if(b[2] < 'D' && d[2] < 'D' || b[2] > 'C' && d[2] > 'C')
		cout <<  "1";
	else
	{
		cout << "00";
		return 0;
	}
	if(b[2] - 1 == d[2] || d[2]-1 == b[2])
		cout << "1";
	else
		cout << "0";	
	return 0;
}
