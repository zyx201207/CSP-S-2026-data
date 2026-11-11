//GZ-J00494 贺举柱 遵义航天中学
#include <bits/stdc++.h>
using namespace std;
int n[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		n[0]=1;
		int x,y;
		x=(b[0]-48)*(10+b[1]-48);
		y=(d[0]-48)*(10+d[1]-48);
		if(x==y) 
		{
			n[1]=1;
			if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E')
			{
				n[2]=1;
				if(abs(b[2]-d[2])==1)
				{
					n[3]=1;
				}
				else
				{
					n[3]=0;
				}
			}
			else
			{
				n[2]=n[3]=0;
			}
		}
		else
		{
			n[1]=n[2]=n[3]=0;
		}
	}
	else
	{
		n[0]=n[1]=n[2]=n[3]=0;
	} 
	for(int i=0;i<4;i++) cout<<n[i];
	return 0;
}
