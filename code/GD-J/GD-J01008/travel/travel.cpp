#include <bits/stdc++.h>

using namespace std;

#define int long long 
int c1,c2;
string s1,s2;
signed main()
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> c1 >> s1 >> c2 >> s2 ;
	
	if (c1==c2)
	{
		cout << 1 ;
		if (s1.substr(0,2)==s2.substr(0,2))
		{
			cout << 1 ;
			char zf=s1[2];
			char zf1=s2[2];
			
			if (zf>zf1)
				swap(zf,zf1);
				
			if ((zf=='A'&&zf1=='B')||(zf=='A'&&zf1=='C')||(zf=='B'&&zf1=='C')||(zf=='D'&&zf1=='E'))
			{
				cout << 1 ;
				if (!(zf=='A'&&zf1=='C'))
				{
					cout << 1 ;
				} else {
					cout << 0 ;
					return 0;
				}
			} else {
				cout << "00" ;
				return 0;
			}
		} else {
			cout << "000" ;
			return 0;
		}
	} else {
		cout << "0000" ;
		return 0;
	}
	
	return 0;
}
