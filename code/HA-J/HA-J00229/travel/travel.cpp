#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)cout<<'1';
	else
	{
		cout<<"0000\n";
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<'1';
	else 
	{
		cout<<"000\n";
		return 0;
	}
	
	int c=s1[2]-'A',d=s2[2]-'A';
	if(c<3&&d<3||c>=3&&d>=3)
	{
		cout<<'1';
		if(abs(c-d)==1)cout<<"1\n";
		else cout<<"0\n";
	}
	else cout<<"00\n";
	
	return 0;
}
