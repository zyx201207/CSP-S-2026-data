#include<bits/stdc++.h>
using namespace std;
int c1,x1,c2,x2;
char y1,y2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&c1,&x1,&y1,&c2,&x2,&y2);
	if(c1!=c2)printf("0000");
	else if(x1!=x2)printf("1000");
	else if((y1<='C'&&y2>'C')||(y2<='C'&&y1>'C'))printf("1100");
	else
	{
		if(abs(y1-y2)==1)printf("1111");
		else if(y1=='D'&&y2=='F')printf("1111");
		else if(y1=='F'&&y2=='D')printf("1111");
		else printf("1110");
	}
}
