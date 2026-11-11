/*
T3T4 so difficult oh my goshhhhhhhhhh
or im just noob and nerd so i dont know how to do T3
just stop playing zorr before noip.
uhhhhhhhh im so useless.

100 + 100? + 8 + 25
im asking my self if my T1 will boom omggg

//freopen
//	freopen

shitt
hate u again SISIEF
im NERD NOOOOOOOOOOOOOOOBBBBBBBBBBBBBB

there's absolute a bunch of 300+s in my school.

feels so bad

agykakgydadykggifeiwarkgyewkyakdfvsdylvliasldgfilagewriagler

luogu uid: elainya_stars

Gino and Geopelia 99999999999999999999
phigros rks 17.11
NOOOOOOOOOOOOOOOOOOBBBBBBBBBBB
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read()
{
	char c=getchar();int f=1,x=0;
	while(c<'0' || c>'9') {(c=='-')?(f=-1):0;c=getchar();}
	while(c>='0' && c<='9') {x=x*10+(c-'0');c=getchar();}
	return x*f;
}

const int inf=0x3f3f3f3f3f3f3f3f;
const int N=2e6+5;
int _C_,T,n,m,a[N];

void doAA()
{
	if(n<=2) {cout<<"0\n";return ;}
	int dif=a[2]-a[1];
	int p=m/dif*2;
	if(p<4) {cout<<"0\n";return ;}
	cout<<max(0ll,n-p+1)<<'\n';
}

signed main()
{
	fastio;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	_C_=read(),T=read();
	while(T--)
	{
		n=read(),m=read();
		bool AA=1;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2]) AA=0;
		}
		if(AA) {doAA();continue;}
		cout<<"0\n";
	}
	return 0;
}
