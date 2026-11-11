#include<bits/stdc++.h>//ÀîÕşĞù GZ-J00435 
using namespace std;
string s1,s2,c1,c2;
int seat1,seat2,train1,train2;
char a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	seat1 = (s1[0]-'0')*10+(s1[1]-'0');
	seat2 = (s2[0]-'0')*10+(s2[1]-'0');
	train1 = (c1[0]-'0')*10+(c1[1]-'0');
	train2 = (c2[0]-'0')*10+(c2[1]-'0');
	a = s1[2];
	b = s2[2];
	if(train1 == train2)
	{
		cout<<"1";
		if(seat1 == seat2)
		{
			cout<<"1";
			if(((a<='C'&&a>='A')&&(b<='C'&&b>='A'))||((a<='F'&&a>='D')&&(b<='F'&&b>='D')))
			{
				cout<<"1";
				if(a == b+1||b == a+1||(a == 'D'&&b == 'F')||(a == 'F'&&b == 'D'))
				{
					cout<<"1";
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
