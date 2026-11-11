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
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	int a=s1[2],b=s2[2];
	if((a-65)/3==(b-65)/3)
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(s1[2]==s2[2]+1||s1[2]==s2[2]-1)
	{
		cout<<1;
	}
	else if(a==70 and b==68 or a==68 and b==70)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
