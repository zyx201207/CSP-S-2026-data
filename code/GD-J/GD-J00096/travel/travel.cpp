#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			char lc1=s1[2],lc2=s2[2];
			if((lc1<='C'&&lc2<='C')||(lc1>='D'&&lc2>='D'))
			{
				cout<<1;
				if(lc1+1==lc2||lc1-1==lc2)
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<"00";
		}
		else
			cout<<"000"; 
	}
	else
		cout<<"0000";
	return 0;
}  
