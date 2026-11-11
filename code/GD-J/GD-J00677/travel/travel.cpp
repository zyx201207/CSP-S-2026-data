#include<bits/stdc++.h>
using namespace std;
string l1,l2,r1,r2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> l1 >> l2 >> r1 >> r2;
	if(l1 != r1) cout << "0000";
	else
	{
		cout << "1";
		int cnt1 = 0,cnt2 = 0,len1 = 0,len2 = 0;
		while(l2[cnt1] >= '0' && l2[cnt1] <= '9') len1 = len1*10 + (l2[cnt1++]-'0');
		while(r2[cnt2] >= '0' && r2[cnt2] <= '9') len2 = len2*10 + (r2[cnt2++]-'0');
		if(len1 != len2) cout << "000";
		else
		{
			cout << "1";
			//ÔÚa,b,c; 
			char r = l2[cnt1],x = r2[cnt2];
			if(r == 'A' || r == 'B' || r == 'C' && x == 'A' || x == 'B' || x == 'C')
			{
				cout << "1";
				if(r == 'A' && x == 'B') cout << "1";
				else if(r == 'B' && x == 'A' || x == 'C') cout << "1";
				else if(r == 'C' && x == 'B') cout << "1";
				else cout << "0";
			}
			//ÔÚd,f; 
			else if(r == 'D' || r == 'F' && x == 'D' || x == 'F') cout << "11";
			else cout << "00";
		}
	}
	return 0;
}
