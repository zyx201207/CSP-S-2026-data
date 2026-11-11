#include<bits/stdc++.h>
using namespace std;
char c1[3],c2[3],s1[3],s2[3],tt;
int tc,ts;
bool t[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1[1]>>c1[2]>>c2[1]>>c2[2]>>c2[3]>>s1[1]>>s1[2]>>s2[1]>>s2[2]>>s2[3];
	tc=(((int)c1[1])-48)*10+((int)c1[2])-48;
	ts=(((int)s1[1])-48)*10+((int)s1[2])-48;
	if(tc==ts)
	{
		cout<<1;
		t[1]=1;	
	}
	else cout<<0;
	tc=(((int)c2[1])-48)*10+((int)c2[2])-48;
	ts=(((int)s2[1])-48)*10+((int)s2[2])-48;
	if(tc==ts&&t[1]==1)
	{
		cout<<1;
		t[2]=1;
	}
	else cout<<0;
	if((c2[3]=='A'||c2[3]=='C'||c2[3]=='B')&&(s2[3]=='A'||s2[3]=='C'||s2[3]=='B'))
	{
		tc=1;
	}
	if((c2[3]=='D'||c2[3]=='F')&&(s2[3]=='F'||s2[3]=='D'))
	{
		ts=1;
	}
	if(t[2]==1&&(tc==1||ts==1))
	{
		cout<<1;
		t[3]=1;
	}
	else cout<<0;
	if((c2[3]=='C'||c2[3]=='D')&&(s2[3]=='C'||s2[3]=='D'))
	{
		cout<<0;
		return 0;
	}
	int r=0;
	if((c2[3]-s2[3]==1)||(c2[3]-s2[3]==-1))r=1;
	if((c2[3]=='D'||c2[3]=='F')&&(s2[3]=='F'||s2[3]=='D')&&t[3]==1)
	cout<<1;
	else if(r==1&&t[3]==1)
	cout<<1;
	else cout<<0;
	
	return 0;
}
