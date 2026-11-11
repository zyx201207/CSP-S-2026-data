#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("trauel.in","r",stdin);
	 freopen("trauel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1[1]==s2[1])
		{
			cout<<"1";
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
			{
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
				{
					cout<<"10";
				}else{
					cout<<"00";
				}
			}else{
				if(s2[2]=='D'||s2[2]=='F')
				{
					cout<<"1";
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	 }else{
	 	cout<<"0000";
	 } 
}
