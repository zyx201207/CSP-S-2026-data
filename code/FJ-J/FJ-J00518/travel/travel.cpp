#include <bits/stdc++.h>
using namespace std;
string chx1,chx2,zow1,zow2;
bool cheeck(char xx,char yy)
{
	if((xx=='A'||xx=='B'||xx=='C')&&(yy=='A'||yy=='B'||yy=='C')) return 1;
	else if((xx=='D'||xx=='F')&&(yy=='D'||yy=='F')) return 1;
	else return 0;
}
bool checkss(char xx,char yy)
{
	if(xx=='A'&&yy=='B') return 1;
	else if(xx=='B'&&yy=='C') return 1;
	else if(xx=='D'&&yy=='F') return 1;
	else if(xx=='B'&&yy=='A') return 1;
	else if(xx=='C'&&yy=='B') return 1;
	else if(xx=='F'&&yy=='D') return 1;
	else return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>chx1>>zow1>>chx2>>zow2;
	if(chx1==chx2) cout<<1;
	else cout<<0;
	if(chx1==chx2)
	{
		bool flag=1;
		for(int i=0;i<2;i++) if(zow1[i]!=zow2[i]) flag=0;
		cout<<flag;
	}
	else cout<<0;
	if(chx1==chx2)
	{
		bool flag=1;
		for(int i=0;i<2;i++) if(zow1[i]!=zow2[i]) flag=0;
		if(flag&&cheeck(zow1[2],zow2[2])) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if(chx1==chx2)
	{
		bool flag=1;
		for(int i=0;i<2;i++) if(zow1[i]!=zow2[i]) flag=0;
		if(flag&&cheeck(zow1[2],zow2[2])&&checkss(zow1[2],zow2[2])) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
} 
