#include<bits/stdc++.h>
#define int long long
using namespace std;
bool fun1(char a, char b)
{
	if((a == 'A' && b == 'B') || (a == 'B' && b == 'A'))  return true;
	else if((a == 'A' && b == 'C') || (a == 'C' && b == 'A'))  return true;
	else if((a == 'B' && b == 'C') || (a == 'C' && b == 'B'))  return true;
	else if((a == 'D' && b == 'F') || (a == 'F' && b == 'D'))  return true;
	else  return false;
	
}
bool fun2(char a, char b)
{
	if((a == 'A' && b == 'B') || (a == 'B' && b == 'A'))  return true;
	else if((a == 'B' && b == 'C') || (a == 'C' && b == 'B'))  return true;
	else if((a == 'D' && b == 'F') || (a == 'F' && b == 'D'))  return true;
	else  return false;
}
signed main()
{
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int c1a = (c1[0] - '0') * 10 + (c1[1] - '0');
	int c2a = (c2[0] - '0') * 10 + (c2[1] - '0');
	int s1a = (s1[0] - '0') * 10 + (s1[1] - '0');
	int s2a = (s2[0] - '0') * 10 + (s2[1] - '0');
	int s1b = (s1[2] - 'A' + (s1[2] == 'F' ? 0 : 1));
	int s2b = (s2[2] - 'A' + (s2[2] == 'F' ? 0 : 1));
	if(c1a == c2a)  cout << 1;
	else  cout << 0;
	if((c1a == c2a) && (s1a == s2a))  cout << 1;
	else  cout << 0;
	if((c1a == c2a) && (s1a == s2a) && (fun1(s1[2], s2[2])))  cout << 1;
	else  cout << 0;
	if(abs(s1b - s2b) == 1 && fun2(s1[2], s2[2]))  cout << 1;
	else  cout << 0;
	return 0;
}
//02 01A 03 01A
