#include<bits/stdc++.h>//最和蔼可亲的一题 
using namespace std;
void comp(char a,char b)
{
	if(a + 1 == b || a - 1 == b)
	{
		cout<<1;
		return;
	}
	cout<<0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2)
	{
		cout<<"0000";
		return 0;
	}//排除不是同一车厢情况 
	else
	{
		cout<<1;//是同一个车厢 
		
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout<<1;//是同一排 
			
			if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
			{
				
				if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
				{
					cout<<1;//s2与s1同侧 
					
					comp(s1[2],s2[2]); 
				}//s2在过道下面？
				
				else
				{
					cout<<0;
					cout<<0;
				}//2与s1不在同一排
				 
			} //s1在过道下面？ 
			else
			{
				
				if(s2[2] == 'D' || s2[2] == 'F')
				{
					cout<<1;//s2与s1同侧 
					
					comp(s1[2],s2[2]);
				}//s2在过道上面？
				 
				else
				{
					cout<<0;
					cout<<0;
				}//s2与s1不在同一排 
				
			}//s1在过道上面
			 
		}//同一排？ 
		
		else
		{
			cout<<0;
			cout<<0;
			cout<<0;
		}//非同一排 
		
	}
	
	return 0;
}
