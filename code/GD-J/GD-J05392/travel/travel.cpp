#include <bits/stdc++.h>
using namespace std;
char res1, res2;
int numa = 0, cnta = 0, numb = 0, cntb = 0, len1, len2, flag = 1;
string ca, sa, cb, sb;
bool checks(char cur1, char cur2)
{
	if ((cur1 == 'D' || cur1 == 'F') && (cur2 == 'D' || cur2 == 'F'))
		return true;
	if ((cur1 == 'A' || cur1 == 'B' || cur1 == 'C') && (cur2 == 'A' || cur2 == 'B' || cur2 == 'C'))
		return true;
	return false;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> ca >> sa >> cb >> sb;
	len1 = sa.size();
	len2 = sb.size();
	for (int i = 0; i < ca.size(); i++)
		numa = numa * 10 + (ca[i] - '0');
	for (int i = 0; i < len1 - 1; i++)
		cnta = cnta * 10 + (sa[i] - '0');
	res1 = sa[len1 - 1];
	for (int i = 0; i < cb.size(); i++)
		numb = numb * 10 + (cb[i] - '0');
	for (int i = 0; i < len2 - 1; i++)
		cntb = cntb * 10 + (sb[i] - '0');
	res2 = sb[len2 - 1];
	if (numa == numb)
		cout << 1;
	else
	{
		cout << 0;
		flag = 0;
	}
	if (flag && cnta == cntb)
		cout << 1;
	else
	{
		cout << 0;
		flag = 0;
	}
	if (flag && checks(res1, res2))
		cout << 1;
	else
	{
		cout << 0;
		flag = 0;
	}
	if (flag)
	{
		if ((res1 == 'D' && res2 == 'F') || (res1 == 'F' && res2 == 'D'))
			cout << 1;
		else if ((res1 == 'A' && res2 == 'B') || (res1 == 'B' && res2 == 'A') || (res1 == 'B' && res2 == 'C') || (res1 == 'C' && res2 == 'B'))
			cout << 1;
		else
		{
			cout << 0;
			flag = 0;
		}
	}
	else
		cout << 0;
	return 0;
}
