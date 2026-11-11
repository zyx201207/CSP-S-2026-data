#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char e=b[0]+b[1];
	char f=b[2];
	char g=d[0]+d[1];
	char h=d[2];
	if(a==c)
		cout<<"1";
	else
		cout<<"0";
	if((e==g)&&(a==c))
		cout<<"1";
	else 
		cout<<"0";
	if((e==g)&&((f<'D'&&h<'D')||(f>'C'&&h>'C'))&&(a==c))
		cout<<"1";
	else
		cout<<"0";
	if((e==g)&&((f<'D'&&h<'D')||(f>'C'&&h>'C'))&&(abs(f-h)==1)&&(a==c))
		cout<<"1";
	else
		cout<<"0";
	return 0;
 } 
