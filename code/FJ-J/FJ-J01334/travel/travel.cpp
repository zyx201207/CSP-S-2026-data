#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)//座位是否在同一节车厢
	{
		cout<<"1";
		int s3=(s1[0]-'0')*10+s1[1]-'0';
		int s4=(s2[0]-'0')*10+s2[1]-'0';
		if(s3==s4)//座位是否在同一排
		{
			cout<<"1";
			s3=s1[2]-'A';
			s4=s2[2]-'A';
			if((s3>2&&s4>2)||(s3<3&&s4<3))//座位是否位于过道的同一侧
			{
				cout<<"1";
				if(s3-s4==1||s4-s3==1)//两张车票对应的座位是否相邻
					cout<<"1";
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	
	
	
	return 0;
}
