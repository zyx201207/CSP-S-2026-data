#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1,s2,c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
//	输出 
	if (c1==c2)//两张车票对应的座位是否在同一节车厢
	{
		cout<<1;
		if (s1[0]==s2[0] && s1[1]==s2[1])//两张车票对应的座位是否在同一节车厢的同一排
		{
			cout<<1;
			if ((s1[2]=='D' && s2[2]=='E') || (s1[2]=='E' && s2[2]=='D'))//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
			{
				cout<<11;
			}
			if (s1[2]<='C' && s2[2]<='C' && s1[2]>='A' && s2[2]>='A')
			{
				cout<<1;
				if ( (s1[2]!='C' && s2[2]!='C') || (s1[2]!='A' && s2[2]!='A') )//两张车票对应的座位是否相邻
				{
					cout<<1;
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
