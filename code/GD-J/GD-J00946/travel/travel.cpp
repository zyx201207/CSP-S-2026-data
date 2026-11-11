#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a==b)cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	} 
	if(x[0]==y[0]&&x[1]==y[1])cout<<1;
	else
	{
		cout<<"000";
		return 0;
	} 
	int c=x[2]-'A'-(x[2]=='F'),d=y[2]-'A'-(y[2]=='F');
	if((c<=2&&d<=2)||(c>=3&&d>=3))cout<<1;
	else
	{
		cout<<"00";
		return 0;
	} 
	if((c-d==1)||(d-c==1))cout<<1;
	else
	{
		cout<<"0";
		return 0;
	} 
	return 0;
} 
