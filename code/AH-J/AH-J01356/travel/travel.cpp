#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1!=c_2)cout<<"0000";
	else if(s_1[0]!=s_2[0]||s_1[1]!=s_2[1])cout<<"1000";
	else
	{
		char a=s_1[2],b=s_2[2];
		if(a<='C'&&b<='C'||a>='D'&&b>='D')
		{
			if(a>='D'&&b>='D')cout<<"1111";
			else
			{
				if(a>b)
				{
					char t=a;
					a=b;
					b=t;
				}
				if(a=='A'&&b=='C')cout<<"1110";
				else cout<<"1111";
			}
		}
		else cout<<"1100";
	}
	return 0;
}
