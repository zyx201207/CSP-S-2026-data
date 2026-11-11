#include<bits/stdc++.h>
using namespace std;
struct 	weizhi
{
	string cx,zw;
}r,x;
int main()
{
	//freopen("travel1.in","r",stdin);
	//freopen("travel1.out","w",stdout);
	cin>>r.cx>>r.zw>>x.cx>>x.zw;
	if(r.cx==x.cx)
	{
		printf("1");
		if(r.zw[0]==x.zw[0]&&r.zw[1]==x.zw[1])
		{
			printf("1");
			if(r.zw[2]<='C'&&x.zw[2]<='C')
			{
				printf("1");
				if(r.zw[2]=='B'||x.zw[2]=='B')
				printf("1");
				else printf("0");
			}
			else if(r.zw[2]>='D'&&x.zw[2]>='D')
			{
				printf("11");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
