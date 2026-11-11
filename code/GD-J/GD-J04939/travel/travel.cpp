#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool n = 0; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//别忘记接触注释！！！！！ 
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2)//相同车厢 
	{
		n = 1;
		cout<<1;
	}
	else
	{
	
		cout<<0;
	}
	string a,b;
	a = s1[0]+s1[1];
	b = s2[0]+s2[1];
	char e = char(s1[2]);
	char f = char(s2[2]);
	int flag = 0;
	bool m = 0;//是否是同一排 
	if(n&&a==b)//同一排 
	{
		flag++;
		m = 1;
		cout<<1;
	}
	else
	{ 
		cout<<0;
	}
	
	
	if(n&&m&&((e-'A'+1<=3&&f-'A'+1<=3)||(e-'A'+1>3&&f-'A'+1>3)))//同一侧 
	{
		flag++; 
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	
	
	if(n&&m&&flag>=2&&(e-'A'+2==f-'A'+1||e-'A'+1==f-'A'+2))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}

	return 0;
}
