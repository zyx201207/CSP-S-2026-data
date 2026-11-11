#include<bits/stdc++.h>
using namespace std;
int a;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		cout<<"1";
	}
	else cout<<"0";
	if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<"1";
	}
	else cout<<"0";
	if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1]&&abs(s1[2]-s2[2])==1&&s1[2]!=67&&s1[2]!=67)
	{
		cout<<"1";
		a=1;
	}
	else if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1]&&abs(s1[2]-s2[2])==2&&max(s1[2],s2[2])==68)
	{
		cout<<"0";
		a=0;
	}
	else if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1]&&abs(s1[2]-s2[2])==2&&max(s1[2],s2[2])==67)
	{
		cout<<"1";
		a=0;
	}
    else if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1]&&abs(s1[2]-s2[2])==2&&max(s1[2],s2[2])==70)
	{
		cout<<"1";
		a=1;
	}
	else cout<<"0";
	if(a==1)
	{
		cout<<"1";
	}
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
