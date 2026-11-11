#include<iostream>
#include<cstdio>
using namespace std;
long long n,ans;
long long l,c[200005];
char f[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		long long x;
		char y;
		cin >> x >> y;
		l+=x;
		c[i]=x,f[i]=y;
	}
	long long st=0,en=0,stl=l/2,enl=l/2,stp=1,enp=n;
	char stf,enf;
	while(stl||enl)
	{
		if(st==0)
		{
			st=min(c[stp],stl);
			stl-=st,stf=f[stp],stp++;
		}
		if(en==0)
		{
			en=min(c[enp],enl);
			enl-=en,enf=f[enp],enp--;
		}
		long long x = min(st,en);
		st-=x,en-=x;
		if(stf!=enf) ans+=x;
	}
	cout << ans;
	return 0;
}
