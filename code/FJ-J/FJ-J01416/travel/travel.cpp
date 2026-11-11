#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,s_1,c2,s_2;
	char s1,s2;
	scanf("%lld%lld%c%lld%lld%c",&c1,&s_1,&s1,&c2,&s_2,&s2);
	if(1==1)
	{
		if(c1==c2)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	if(2==2)
	{
		if(c1==c2&&s_1==s_2)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	if(3==3)
	{
		if(c1==c2&&s_1==s_2&&(s1<='C'&&s2<='C'||s1>='D'&&s2>='D'))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	if(4==4)
	{
		if(c1==c2&&s_1==s_2&&(s1<='C'&&s2<='C'||s1>='D'&&s2>='D')&&(s1>='D'&&s2>='D'||s1=='A'&&s2=='B'||s1=='B'&&s2=='A'||s1=='B'&&s2=='C'||s1=='C'&&s2=='B'))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	return 0;
}