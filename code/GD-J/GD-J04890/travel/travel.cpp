#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
		cout<<"0000";
	else
	{
		int a=s1[0]*10+s1[1],b=s2[0]*10+s2[1];
		if(a!=b) cout<<"1000";
		else
		{
			if(s1[2]<='C'&&s2[2]>='D'||s1[2]>='D'&&s2[2]<='C')
				cout<<"1100";
			else
			{
				if(s1[2]+1!=s2[2]&&s1[2]-1!=s2[2])
					cout<<"1110";
				else cout<<"1111";
			}
		}
	}
	return 0;
}
