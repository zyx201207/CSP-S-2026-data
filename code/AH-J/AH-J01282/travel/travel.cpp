#include<bits/stdc++.h>
using namespace std;
#define itn int
#define ll long long
int cha,chb,roa,rob;
char zwa,zwb;
bool a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	scanf("%d %d%c %d %d%c",&cha,&roa,&zwa,&chb,&rob,&zwb);
	if(cha==chb)
		a=1;
	if(a && (roa==rob))
		b=1;
	if(zwa=='F')
		zwa='E';
	if(zwb=='F')
		zwb='E';
	if(b && ((zwa>='A' && zwa<='C' && zwb<='C' && zwb>='A')||(zwa>='D' && zwa<='E' && zwb>='D' && zwb<='E')))
		c=1;
	if(a && b && c && abs((int)(zwa-zwb))==1)
		d=1;
	printf("%d%d%d%d",a,b,c,d);

	return 0;
}

