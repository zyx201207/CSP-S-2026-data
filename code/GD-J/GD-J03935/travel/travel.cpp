#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2)
	{
		cout<<"1";
		if(s1.substr(0, 2) == s2.substr(0, 2))
		{
			cout<<"1";
			char a = s1[2], b = s2[2];
			if(a <= 'C' && b <= 'C' || a >= 'D' && b >= 'D')
			{
				cout<<"1";
				if(a <= 'C' && b <= 'C' && abs((int)(a) - (int)(b)) == 1 || a >= 'D' && b >= 'D') cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
