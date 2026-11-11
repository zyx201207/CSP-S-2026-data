//GZ-J00209 遵义四中  邱果 
#include <bits/stdc++.h>
using namespace std;
int a1,b1,f1,f2,t1,t2;
string c1,c2,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a2>>c2>>b2;
	if (c1[0]=='0')
	{
		a1=c1[1]-'0';
	}else
	{
		a1=(c1[1]-'0')+(c1[0]-'0')*10;
	}
	
	if (c2[0]=='0')
	{
		b1=c2[1]-'0';
	}else
	{
		b1=(c2[1]-'0')+(c2[0]-'0')*10;
	}
	
	if (a2[0]=='0')
	{
		f1=a2[1]-'0';
	}else
	{
		f1=(a2[1]-'0')+(a2[0]-'0')*10;
	}
	t1=a2[2]-'A';
	if (b2[0]=='0')
	{
		f2=b2[1]-'0';
	}else
	{
		f2=(b2[1]-'0')+(b2[0]-'0')*10;
	}
	t2=b2[2]-'A';
	if ((a1==b1))cout<<"1";
else cout<<"0";
	if ((a1==b1)&&(f1==f2))cout<<"1";
else cout<<"0";
	if ((a1==b1)&&(f1==f2) &&((t2>2 && t1>2)||(t2<=2 && t1<=2)))cout<<"1";
else cout<<"0";
if ((a1==b1)&&(f1==f2) &&((t2>2 && t1>2)||(t2<=2 && t1<=2))&& (abs(t2-t1)==1))cout<<"1";
else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

