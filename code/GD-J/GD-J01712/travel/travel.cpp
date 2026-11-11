#include <bits/stdc++.h>
using namespace std;
int c1,s1,p1,c2,s2,p2;
char m,n;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> m >> c2 >> s2 >> n;
	p1=int(m)-64;
	p2=int(n)-64;
	if(c1==c2)//同一车厢 
	{
		cout << 1;
		if(s1==s2)//同一排 
		{
			cout << 1;
			if((p1<=3 && p2<=3)||(p1>3 && p2>3))//同一侧 
			{
				cout << 1;
				if(max(p1,p2)-min(p1,p2)==1 && max(p1,p2)!=4)//相邻座位 
					cout << 1;
				else//不相邻 
					cout << 0;
			}
			else//不同侧 
			{
				cout << "00";
			} 
				
		}
		else//不同排 
		{
			cout << "000";
		}
	}
	else//不同车厢 
	{
		cout << "0000";
	}
	//cout << p1;
	return 0;
 } 
