#include<bits/stdc++.h>
using namespace std;
string a,c;
int flag;
char b[3],d[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		flag++;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			flag++;
			if('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C')
			{
				flag++;
				if(b[2]=='A'&&d[2]=='B') flag++;
				else if(d[2]=='A'&&b[2]=='B') flag++;
				else if(d[2]=='B'&&b[2]=='C') flag++;
				else if(d[2]=='C'&&b[2]=='B') flag++;
			}
			else if('D'<=b[2]&&b[2]<='E'&&'D'<=d[2]&&d[2]<='E')
			{
				flag++;
				if(b[2]=='D'&&d[2]=='E') flag++;
				else if(d[2]=='D'&&b[2]=='E') flag++;
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		if(flag)
		{
			cout<<1;
			flag--;
		}
		else cout<<0;
	}
	return 0;
}
