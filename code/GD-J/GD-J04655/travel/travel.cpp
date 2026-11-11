#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
bool f[4];
bool Check(char x,char y)
{
	if(x=='A'&&y=='B') return 1;
	if(x=='B'&&(y=='A'||y=='C')) return 1;
	if(x=='C'&&y=='B') return 1;
	if(x=='D'||x=='F') return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		f[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			f[1]=1;
			int tmp1,tmp2;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') tmp1=1;
			if(s1[2]=='D'||s1[2]=='F') tmp1=2;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') tmp2=1;
			if(s2[2]=='D'||s2[2]=='F') tmp2=2;
			if(tmp1==tmp2)
			{
				f[2]=1;
				f[3]=Check(s1[2],s2[2]);
			}
		}
	}
	cout<<f[0]<<f[1]<<f[2]<<f[3];
	return 0;
}
