#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,l1,l2;
bool check1(char a,char b)
{
	return ((a >= 'A' && a <= 'C') && (b >= 'D' && b <= 'E'));
}
bool check2(char a,char b)
{
	if(a >= 'A' && a <= 'B')
		return b == a+1;
	return b == 'F';
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) {
		cout << "0000";
		return 0;
	}
	cout << 1;
	
	l1 = s1.substr(0,2);
	l2 = s2.substr(0,2);
	if(l1 != l2) {
		cout << "000";
		return 0;
	}
	cout << 1;
	
	if(check1(min(s1[2],s2[2]),max(s1[2],s2[2])))
	{
		cout << "00";
		return 0;
	}
	cout << 1;
	
	if(check2(min(s1[2],s2[2]),max(s1[2],s2[2])))
	{
		cout << 1;
	}else cout << 0;
	return 0;
}
