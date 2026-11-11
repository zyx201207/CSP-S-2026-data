#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		if(c[0]+c[1]==d[0]+d[1])
		{
			if(c[2]<='C'&&d[2]<='C'||c[2]>='D'&&d[2]>='D')
			{
				if(c[2]=='A'&&d[2]=='B'||c[2]=='B'&&d[2]=='A'||c[2]=='B'&&d[2]=='C'||c[2]=='C'&&d[2]=='B'||c[2]=='D'&&d[2]=='F'||c[2]=='F'&&d[2]=='D') cout<<1111;
				else cout<<1110;
			}
			else cout<<1100;
		}
		else cout<<1000;
	}
	else cout<<"0000";
	return 0;
}
