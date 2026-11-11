#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

int f[202];
int g[202];

char a[10],b[10],c[10],d[10];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	f['A']=f['B']=f['C']=1;
	f['D']=f['F']=2;
	g['A']=1;
	g['B']=2;
	g['C']=3;
	g['D']=4;
	g['F']=5;
	
	scanf("%s%s%s%s",a,b,c,d);
	if (a[0]==c[0]&&a[1]==c[1]) putchar('1');
	else putchar('0');
	
	if (a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]) putchar('1');
	else putchar('0');
	
	if (a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]&&f[b[2]]==f[d[2]]) putchar('1');
	else putchar('0');
	
	if (a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]&&f[b[2]]==f[d[2]]&&abs(g[b[2]]-g[d[2]])==1) putchar('1');
	else putchar('0');
	
	return 0;
}
