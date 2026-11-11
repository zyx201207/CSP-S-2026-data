#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,c,d,e,f,x1,y1,x2,y2;
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld ",&a[i]);
		scanf("%c",&b[i]);
	}
//	cout<<b[1]<<b[2]<<b[3]; 
	x1=1;
	x2=n;
	y1=a[x1];
	y2=a[x2];
	while(x1<=x2)
	{
		if(y1>y2)
		{
			y1=y1-y2;
			if(b[x1]==b[x2])
			{
				x2--;					
				y2=a[x2];
			}
			else
			{
				x2--;
				c=c+y2;
				y2=a[x2];
			}
		}
		else
		if(y1<y2)
		{
			y2=y2-y1;				
			if(b[x1]==b[x2])
			{
				x1++;
				y1=a[x1];
			}
			else
			{
				x1++;
				c=c+y1;
				y1=a[x1];
			}
		}
		else
		if(y1==y2)
		{
			if(b[x1]==b[x2])
			{
				x1++;
				x2--;
				y1=a[x1];
				y2=a[x2];
			}
			else
			{
				c=c+y1;
				x1++;
				x2--;
				y1=a[x1];
				y2=a[x2];
			}
		}
	}
	cout<<c;
	return 0;
}
