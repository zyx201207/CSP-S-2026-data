#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c11,c22,s2;
	cin>>c11>>s1>>c22>>s2;
	int c1=(c11[0]-'0')*10+(c11[1]-'0'),c2=(c22[0]-'0')*10+(c22[1]-'0');
	int s11=(s1[0]-'0')*10+(s1[1]-'0'),s22=(s2[0]-'0')*10+(s2[1]-'0');
	int s3=s1[2]-'A',s4=s2[2]-'A';
	//cout<<c1<<c2;
	if(c1==c2)
	{
		cout<<"1";
		if(s11==s22)
		{
			cout<<"1";
			if(s1[2]<='C')
			{
				if(s2[2]<='C')
				{
					cout<<"1";
					if(abs(s4-s3)==1)cout<<"1";
					else cout<<"0";
				}
				else cout<<"00";
			}
			if(s1[2]>'C')
			{
				if(s2[2]>'C')
				{
					cout<<"1";
					if(abs(s4-s3)==1)cout<<"1";
					else cout<<"0";
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
