#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	if(a1 != b1)
	{
		cout << "0000";
		return 0;
	}
	else
		cout << "1";
	int cnt1 = 0,cnt2 = 0;
	char c1,c2;
	cnt1 = (a2[0]-'0')*10 + (a2[1]-'0');
	cnt2 = (b2[0]-'0')*10 + (b2[1]-'0');
	c1 = a2[2];
	c2 = b2[2];
	if(cnt1 != cnt2)
	{
		cout << "000";
		return 0;
	}
	else
		cout << "1";
	if(c1=='A'&&c2=='D' || c1=='A'&&c2=='F' || c1=='B'&&c2=='D' || c1=='B'&&c2=='F' || c1=='C'&&c2=='D' || c1=='C'&&c2=='F')
	{
		cout << "00";
		return 0;
	}
	else if(c2=='A'&&c1=='D' || c2=='A'&&c1=='F' || c2=='B'&&c1=='D' || c2=='B'&&c1=='F' || c2=='C'&&c1=='D' || c2=='C'&&c1=='F')
	{
		cout << "00";
		return 0;
	}
	else
		cout << "1";
	int cnt = abs(c1-c2);
	if(cnt == 1)
		cout << 1;
	else
		cout << 0;
	return 0;
}
