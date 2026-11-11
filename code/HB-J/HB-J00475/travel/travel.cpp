#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int s=0;
	if(a==c)
	{
		s++;
	}
	else
	{
		printf("0000");
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1])
	{
		s++;
	}
	else
	{
		printf("1000");
		return 0;
	}
	if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))
	{
		s++;
	}
	else
	{
		printf("1100");
		return 0;
	}
	if(b[2]-d[2]==1||d[2]-b[2]==1)
	{
		s++;
	}
	else
	{
		printf("1110");
		return 0;
	}
	printf("1111");
	return 0;
}
