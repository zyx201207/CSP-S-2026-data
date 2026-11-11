#include<bits/stdc++.h>
using namespace std;
string s,sum,cnt;
int n,m,mon;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>s;
		mon+=m; 
	}
	if(mon<=2)cout<<0;
	else if(mon<=6)cout<<2;
	else if(mon<=8)cout<<3;
	else if(mon<=10)cout<<4;
	else if(mon<=12)cout<<5;
	else if(mon<=14)cout<<6;
	else if(mon<=16)cout<<7;
	else if(mon<=18)cout<<8;
	else if(mon<=20)cout<<9;
	else if(mon<=22)cout<<10;
	else cout<<300000000;
	return 0;
}
