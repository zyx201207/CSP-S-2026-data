#include<bits/stdc++.h>
using namespace std;
int read()//long long?
{
	char c=getchar();
	int fu=1,res=0;
	while(c<'0'||c>'9')
	{
		if(c=='-') fu=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return res*fu;
}
void write(int x)//long long?
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x<=9)
	{
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	return 0;
}//4 2 3 15 12 12
