#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char s1[10],s2[10];
int c1,c2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0,b=0,c=0,d=0;
	cin>>c1;
	for(int i=0;i<3;++i)
	{
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<3;++i)
	{
		cin>>s2[i];
	}
	if(c1==c2&&c1>=2&&c1<=16&&c2>=2&&c2<=16)
	{
		a=1;
	}
	if(a==1&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		b=1;
	}
	if(a==1&&b==1&&s1[2]=='A'&&s2[2]=='B'||a==1&&b==1&&s1[2]=='B'&&s2[2]=='A'||a==1&&b==1&&s1[2]=='B'&&s2[2]=='C'||a==1&&b==1&&s1[2]=='C'&&s2[2]=='B'||a==1&&b==1&&s1[2]=='D'&&s2[2]=='E'||a==1&&b==1&&s1[2]=='E'&&s2[2]=='D'||a==1&&b==1&&s1[2]=='A'&&s2[2]=='C'||a==1&&b==1&&s1[2]=='C'&&s2[2]=='A')
	{
		c=1;
	}
	if(a==1&b==1&&c==1&&s1[2]=='A'&&s2[2]=='B'||a==1&b==1&&c==1&&s1[2]=='B'&&s2[2]=='A'||a==1&b==1&&c==1&&s1[2]=='B'&&s2[2]=='C'||a==1&b==1&&c==1&&s1[2]=='C'&&s2[2]=='B'||a==1&b==1&&c==1&&s1[2]=='D'&&s2[2]=='E'||a==1&b==1&&c==1&&s1[2]=='E'&&s2[2]=='D')
	{
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
