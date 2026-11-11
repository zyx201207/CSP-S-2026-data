#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>a1>>b1;
	if(a==a1)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(b[0]==b1[0]&&b[1]==b1[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(((b[2]>='A'&&b[2]<='C')&&(b1[2]>='A'&&b1[2]<='C'))||((b[2]=='D'||b[2]=='E')&&(b1[2]=='D'||b1[2]=='E')))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(b[2]-1==b1[2]||b[2]+1==b1[2])
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
