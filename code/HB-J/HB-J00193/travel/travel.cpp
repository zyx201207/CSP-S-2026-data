#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string _c1,_s1,_c2,_s2;
	cin>>_c1>>_s1>>_c2>>_s2;
	if(_c1==_c2)
	{
		cout<<1;
		if(_s1[0]==_s2[0]&&_s1[1]==_s2[1])
		{
			cout<<1;
			if((_s1[2]<='C'&&_s2[2]<='C')||(_s1[2]>='D'&&_s2[2]>='D'))
			{
				cout<<1;
				if(_s1[2]==char(_s2[2]+1)||_s1[2]==char(_s2[2]-1))
				{
					if(_s1[2]=='C'&&_s2[2]=='D')
					{
						cout<<0;
					}
					else if(_s1[2]=='D'&&_s2[2]=='C')
					{
						cout<<0;
					}
					else cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
			
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
