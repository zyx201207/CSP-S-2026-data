#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2;
	char c1,c2;
	scanf("%2d %2d%c %2d %2d%c",&a1,&b1,&c1,&a2,&b2,&c2);
	string s={'0','0','0','0'};
	if(a1==a2)
	{
		s[0]='1';
		if(b1==b2)
		{
			s[1]='1';
			if((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C'))
			{
				s[2]='1';
				int d1=c1-'A',d2=c2-'A';
				if(d2>d1)
					swap(d1,d2);
				if(d1-d2==1&&!(d1==3&&d2==2))
					s[3]='1';
			}
		}
	}
	cout<<s;
	return 0;
}
