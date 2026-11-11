#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define ll long long
string c1, s1, c2, s2;
bool ok;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	//1
	if(c1 == c2) cout << 1;
	else if(c1 != c2)cout << 0;
	//2
	ok = 0;
	if(s1[0] == s2[0] && s1[1] == s2[1] && c1 == c2)
	{
		cout << 1;
		ok = 1;
	}
	else cout << 0;
	//3
	char h1 = s1[2];
	char h2 = s2[2];
	if(ok && c1 == c2)
	{
		if(h1 == 'A' && (h2 == 'B' || h2 == 'C')) cout << 1;
		else if(h1 == 'B' && (h2 == 'A' || h2 == 'C')) cout << 1;
		else if(h1 == 'C' && (h2 == 'B' || h2 == 'A')) cout << 1;
		else if(h1 == 'D' && h2 == 'F') cout << 1;
		else if(h1 == 'F' && h2 == 'D') cout << 1;
		else cout << 0;
	}
	else cout << 0;
	//4
	if(ok && c1 == c2)
	{
		if(h1 == 'A' && h2 == 'B') cout << 1;
		else if(h1 == 'B' && (h2 == 'A' || h2 == 'C')) cout << 1;
		else if(h1 == 'C' && h2 == 'B') cout << 1;
		else if(h1 == 'D' && h2 == 'F') cout << 1;
		else if(h1 == 'F' && h2 == 'D') cout << 1;
		else cout << 0;
	}
	else cout << 0;
	return 0; 
}
