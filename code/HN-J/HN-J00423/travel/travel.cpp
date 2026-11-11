#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;//小 R的车厢号座位号,小 X 的车厢号、座位号
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		printf("1");
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			printf("1");
			int f1=0,f2=0;//过道的哪一边
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
			{
				f1=1;
			}
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
			{
				f2=1;
			}
			if(f1==f2)
			{
				printf("1");
				if(f1==0||s1[2]=='B'||s2[2]=='B')
				{
					printf("1");
				}
				else
				{
					printf("0");
				}
			}
			else
			{
				printf("00");
			}
		}
		else
		{
			printf("000");
		}
	}
	else
	{
		printf("0000");
	}
	return 0;
}
/*两张车票对应的座位是否在同一节车厢；*
 两张车票对应的座位是否在同一节车厢的同一排；*
 两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
 两张车票对应的座位是否相邻*/ 
