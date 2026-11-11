#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,c,d;
int x,y;
char s,t;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) printf("1");
	else
	{
		printf("0000\n");
		return 0;
	}
	x=0,y=0;
	for(int i=0;i<b.length();i++)
	{
		if(b[i]>='0'&&b[i]<='9') x=x*10+b[i]-'0';
		else s=b[i];
	}
	for(int i=0;i<d.length();i++)
	{
		if(d[i]>='0'&&d[i]<'9') y=y*10+d[i]-'0';
		else t=d[i];
	}
	if(x==y) printf("1");
	else
	{
//		cout<<x<<" "<<y<<endl;
		printf("000\n");
		return 0;
	}
	if(s=='A'&&(t=='B'||t=='C')) printf("1");
	else if(s=='B'&&(t=='A'||t=='C')) printf("1");
	else if(s=='C'&&(t=='B'||t=='A')) printf("1");
	else if(s=='D'&&t=='F') printf("1");
	else if(s=='F'&&t=='D') printf("1");
	else 
	{
		printf("00\n");
		return 0;
	}
	if(s=='A'&&t=='B') printf("1");
	else if(s=='B'&&(t=='A'||t=='C')) printf("1");
	else if(s=='C'&&t=='B') printf("1");
	else if(s=='D'&&t=='F') printf("1");
	else if(s=='F'&&t=='D') printf("1");
	else
	{
		printf("0\n");
		return 0;
	}
	return 0;
}
