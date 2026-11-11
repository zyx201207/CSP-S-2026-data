#include <bits/stdc++.h>
#define ll long long

using namespace std;

string cr,sr,cx,sx;
int s1,s2;

int main()
{
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> cr >> sr >> cx >> sx;
	
	if(cr != cx) cout << "0000";
	else
	{
		cout << 1;
		if(sr[0] != sx[0] || sr[1] != sx[1]) cout << "000";
		else
		{
			cout << 1;
			if(sr[2] == 'D' || sr[2] == 'F') s1 = 1;
			if(sx[2] == 'D' || sx[2] == 'F') s2 = 1;
			if(s1 != s2) cout << "00";
			else
			{
				cout << 1;
				if(s1 == 1) cout << 1;
				else
				{
					if((sr[2] == 'A' || sr[2] == 'C') && (sx[2] == 'A' || sx[2] == 'C')) cout << 0;
					else cout << 1;
				}
			}
		}
	}
	
	
	return 0;
}
