#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string x,y;
	cin >> a >> x >> b >> y;
	int x1=(x[0]-'0')*10+x[1]-'0';
	int y1=(y[0]-'0')*10+y[1]-'0';
	bool s1,s2,s3,s4;
	if(a==b)
	{
		s1=1;
	}
	else
	{
		s1=0;
	}
	if((x1==y1)&&(s1))
	{
		s2=1;
	}
	else
	{
		s2=0;
	}
	if((s2)&&((y[2]<='C'&&x[2]<='C')||(y[2]>'C'&&x[2]>'C')))
	{
		s3=1;
	}
	else
	{
		s3=0;
	}
	if((s3)&&(abs(x[2]-y[2])==1))
	{
		s4=1;
	}
	else
	{
		s4=0;
	}
	cout << s1 << s2 << s3 << s4;
	return 0;
}
