#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	
	string a = "", b = "";
	char x = s1[2], y = s2[2];
	a += s1[0],a += s1[1];
	b += s2[0],b += s2[1];
	int n = stoi(a),m = stoi(b);
	
	if(c1 == c2) 
	{
		cout<<1;
		if(n == m) 
		{
			cout<<1;
			if(x >= 'A' && x <= 'C' && y >= 'A' && y <= 'C' || x >= 'D' && x <= 'F' && y >= 'D' && y <= 'F') 
			{
				cout<<1;
				if(abs(x-y) == 1) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
	return 0;
}
