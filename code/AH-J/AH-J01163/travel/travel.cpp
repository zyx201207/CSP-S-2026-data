#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2)
	{
		cout<<"0000";
	}else{
		if(s1.substr(0,2) != s2.substr(0,2))
		{
			cout<<"1000";
		}else{
			char a = s1[2];
			char b = s2[2];
			if(!(((a == 'A' && b == 'B')
			  || (a == 'B' && b == 'C')
			  || (a == 'A' && b == 'C')
			  || (a == 'D' && b == 'F'))
			  ||((b == 'A' && a == 'B')
			  || (b == 'B' && a == 'C')
			  || (b == 'A' && a == 'C')
			  || (b == 'D' && a == 'F'))))
			  {
				  cout<<"1100";
			  }else{
				  if(!(((a == 'A' && b == 'B')
				|| (a == 'B' && b == 'C')
				|| (a == 'D' && b == 'F'))
				||((b == 'A' && a == 'B')
				|| (b == 'B' && a == 'C')
				|| (b == 'D' && a == 'F'))))
				{
					cout<<"1110";
				}else{
					cout<<"1111";
				}
			  }
		}
	}
	return 0;
}
