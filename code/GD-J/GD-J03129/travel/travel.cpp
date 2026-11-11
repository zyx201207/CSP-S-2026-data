#include<cstdio>
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char s1,s2;
	scanf("%02d %02d%c %02d %02d%c",&a,&b,&s1,&c,&d,&s2);
	if(a!=c)puts("0000");
	else
	{
		putchar('1');
		if(b!=d)puts("000");//b d cha dian gao fan le ne
		else
		{
			putchar('1');
			if((s1<='C'&&s2<='C')||(s1>='D'&&s2>='D'))
			{
				putchar('1');
				if((s1>='D'&&s2>='D')||(s2-s1==1)||(s1-s2==1))putchar('1');
				else putchar('0');
			}
			else puts("00");
		}
	}
	return 0;
}
