#include <bits/stdc++.h>
#define int long long
using namespace std;
//const int N = ;
string c1, s1, c2, s2;
int check()
{
	if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A'))
		return 2;
	if((s1[2]=='A' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='A'))
		return 1;
	if((s1[2]=='B' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='B'))
		return 2;
	if((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D'))
		return 2;
	return 0;
}
signed main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    //cin.tie(nullptr), cout.tie(nullptr);
    //ios::sync_with_stdio(false);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2)
		cout << 1;
	else
	{
		cout << "0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1])
		cout << 1;
	else
	{
		cout << "000";
		return 0;
	}
	if(check()==0)
		cout << "00";
	else if(check()==1)
		cout << "10";
	else
		cout << "11";
    return 0;
}
