#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//1
	if (c1==c2) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	//2
	int x1=(s1[0]-'0')*10+s1[1]-'0';
	int x2=(s2[0]-'0')*10+s2[1]-'0';
	if (x1==x2) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	//3
	if (s1[2]<='C'&&s2[2]>='D' || s2[2]<='C'&&s1[2]>='D')
	{
		cout<<"00";
		return 0;
	}
	else cout<<1;
	//4
	if (abs(s1[2]-s2[2])==1) cout<<1;
	else cout<<0;
	
	return 0;
} 
