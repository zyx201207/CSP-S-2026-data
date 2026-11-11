#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	
	int l1 = 0,l2 = 0;
	l1 = (s1[0]-'0')*10+s1[1]-'0';
	l2 = (s2[0]-'0')*10+s2[1]-'0';
	
	if(c1 == c2)
	{
		cout<<"1";
		if(l1 == l2)
		{
			cout<<"1";
			if(('D' > s1[2] && 'D' > s2[2]) || ('D' <= s1[2] && 'D' <= s2[2]))
			{
				cout<<"1";
				if(('D' <= s1[2] && 'D' <= s2[2]) || abs(s1[2]-s2[2]) == 1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	
	return 0;
}
