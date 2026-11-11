#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rx,rw,xx,xw;
	cin >> rx >> rw >> xx >> xw;
	int f = 1;
	if(rx==xx)
		cout << f;
	else
	{
		f = 0;
		cout << f;
	}
	//to answer q1
	
	
	if(rw[0]==xw[0]&&rw[1]==xw[1])
		cout << f;
	else
	{
		f = 0;
		cout << f;
	}
	
	//to answer q2
	
	
	
	if((rw[2]=='A'||rw[2]=='B'||rw[2]=='C')&&(xw[2]=='A'||xw[2]=='B'||xw[2]=='C'))
		cout << f;
	else if ((rw[2]=='D'||rw[2]=='F')&&(xw[2]=='D'||xw[2]=='F'))
	{
		cout << f << f ;
		return 0;
	}
	else
	{
		f = 0;
		cout << f;
	}
	//to answer q3
	
	
	if((rw[2]=='A'&&xw[2]=='B')||(rw[2]=='B'&&xw[2]=='C')||(rw[2]=='B'&&xw[2]=='A')||(rw[2]=='C'&&xw[2]=='B'))
	{
		cout << f;
	}
	else
	{
		f = 0;
		cout << f;
	}
	//to answer q4
	return 0;
}
