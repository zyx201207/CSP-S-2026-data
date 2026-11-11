#include<cstdio>
#include<iostream>
#include<cstdint>
#include<cmath>
#include<string>
using namespace std;
uint8_t Str_to_int(string String)
{
	//将字符串变成整数 
	uint8_t Return=0;
	for(int i=0;i<String.size();i++)
	{
		//将返回的结果往前移动一位 
		Return*=10;
		//再加上该字符对应数字 
		Return+=String[i]-'0';
	}
	return Return;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string Coach1, Seat1, Coach2, Seat2;
	cin>>Coach1>>Seat1>>Coach2>>Seat2;
	//获取两个人的车厢号 
	int c1=Str_to_int(Coach1), c2=Str_to_int(Coach2);
	//获取两个人的座位排号 
	int Row1=Seat1[0]*10+Seat1[1]-528, Row2=Seat2[0]*10+Seat2[1]-528;
	//使用Table存储每个字母对应走廊哪一侧，以及第几个位置 
	int Table[256]={};
	Table['A']=3+0;
	Table['B']=3+1;
	Table['C']=3+2;
	Table['D']=6+0;
	Table['F']=6+1;
	//获取两个人的座位侧号 
	int Side1=Table[Seat1[2]]/3, Side2=Table[Seat2[2]]/3;
	int Line1=Table[Seat1[2]]%3, Line2=Table[Seat2[2]]%3;
	//输出 
	cout<<(c1==c2);
	cout<<(c1==c2&&Row1==Row2);
	cout<<(c1==c2&&Row1==Row2&&Side1==Side2);
	cout<<(c1==c2&&Row1==Row2&&Side1==Side2&&abs(Line2-Line1)==1);
	return 0;
}
