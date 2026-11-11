#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
int p[10]={0,0,0,0,0};
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a>> b >> c >> d; 
	if(a==c)p[1]=1;
	if(b[0]==d[0]&&b[1]==d[1]&&p[1]==1)p[2]=1;
	if(((b[2]>='A')&&(b[2]<='C')&&(d[2]>='A')&&(d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'))&&p[2]==1)p[3]=1;
	if(p[3]==1)
	{
		if(b[2]>='A'&&b[2]<='C')
		{
			if(b[2]=='B'||d[2]=='B')p[4]=1;
		}
		else
			p[4]=1;
	}
	for(int i=1;i<=4;i++)cout << p[i];
	return 0;
} 
