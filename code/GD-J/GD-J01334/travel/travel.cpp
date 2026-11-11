#include<bits/stdc++.h>
using namespace std;
char a[5],b[5],c[5],d[5];
bool f=0,x=0,y=0,z=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s %s %s",a,b,c,d);
	int cx=(a[0]-'0')*10+a[1]-'0',cy=(c[0]-'0')*10+c[1]-'0';
	if(cx==cy)
	{
		f=1;
		int px=(b[0]-'0')*10+b[1]-'0',py=(d[0]-'0')*10+d[1]-'0';
		if(px==py)
		{
			x=1;
			if(('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C')||('D'<=b[2]&&b[2]<='F'&&'D'<=d[2]&&d[2]<='F'))
			{
				y=1;
				char l=b[2],r=d[2];
				if(l>r)swap(l,r);
				if((l=='D'&&r=='F')||(l=='A'&&r=='B')||(l=='B'&&r=='C'))z=1;
			}
		}
	}
	printf("%d%d%d%d",f,x,y,z);
	return 0;
}
