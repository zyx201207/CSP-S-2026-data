#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			int A=s1[2],B=s2[2];
			if(min(A,B)<='C'&&max(A,B)>='D')
			{
				cout<<"1100";
			}
			else
			{
				if(min(A,B)+1==max(A,B))
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
