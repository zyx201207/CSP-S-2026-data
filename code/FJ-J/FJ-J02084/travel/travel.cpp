#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a[6]={1,2,3,0,5,6};
	if(c1==c2) 
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]) 
		{
			cout<<"1";
			if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'||s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D')
			{
				cout<<"1";
				if(a[s1[2]-'A']==a[s2[2]-'A']-1||a[s1[2]-'A']==a[s2[2]-'A']+1)
					cout<<"1";
				else {cout<<"0"; return 0;}
			}
			else {cout<<"00"; return 0;}
		}
		else {cout<<"000"; return 0;}
	}
	else {cout<<"0000"; return 0;}
}
