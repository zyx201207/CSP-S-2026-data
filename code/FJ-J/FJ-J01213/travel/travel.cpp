#include <bits/stdc++.h>
using namespace std;

string rc1,rc2,xc1,xc2,ans,zuowei1,zuowei2;   
char r,x;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>rc1 >>rc2 >>xc1 >>xc2;
	if(rc1!=xc1)
	{
		cout <<"0000";
		return 0;
	}
	else
	{
		ans[0]='1';
	}
	zuowei1[0]=rc2[0];
	zuowei1[1]=rc2[1];
	zuowei2[0]=xc2[0];
	zuowei2[1]=xc2[1];
	if(zuowei1[1]!=zuowei2[1])
	{
		ans[1]='0';
	}
	else
	{
		ans[1]='1';
	}
	r=rc2[2];
	x=xc2[2];
	if(((r=='A'&&x=='B')||(r=='B'&&x=='A')||(r=='B'&&x=='C')||(r=='C'&&x=='B')||(r=='A'&&x=='C')||(r=='C'&&x=='A')||(r=='D'&&x=='F')||(r=='F'&&x=='D'))&&ans[1]=='1')
	{
		ans[2]='1';
	}
	else
	{
		ans[2]='0';
	}
	if(((r=='A'&&x=='B')||(r=='B'&&x=='A')||(r=='B'&&x=='C')||(r=='C'&&x=='B')||(r=='D'&&x=='F')||(r=='F'&&x=='D'))&&ans[1]=='1')
	{
		ans[3]='1';
	}
	else 
	{
		ans[3]='0';
	}
	cout <<ans[0]<<ans[1] <<ans[2] <<ans[3];
	return 0;
}














//AC!
