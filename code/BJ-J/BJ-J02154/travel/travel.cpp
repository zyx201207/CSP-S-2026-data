#include "bits/stdc++.h"
#define int long long
using namespace std;

string c1,c2;
char s1[4],s2[4];

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c1;

	for(int i=1;i<=3;i++)
    cin >> s1[i];


    cin >> c2;


	for(int i=1;i<=3;i++)
    cin >> s2[i];

		if(c1!=c2)
			cout << "0000";
		else
			cout << "1";
		if(s1[1]==s2[1]&&s1[2]==s2[2])
            cout << "1";
        else
            cout << "0";
		if(s1[3]=='A'||'B'||'C' && s2[3]=='A'||'B'||'C' || s1[3]=='D'||'E' && s2[3]=='D'||'E')
			cout << "1";
		else
			cout << "0";
		if(s1[3]=='A'&& s2[3]=='B' || s1[3]=='B' && s2[3]=='C' || s1[3]=='D'||'E' && s2[3]=='D'||'E')
			cout << "1";
		else
			cout << "0";
	ios::sync_with_stdio(false);

	return 0;
}
