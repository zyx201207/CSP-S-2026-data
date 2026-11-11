#include<bits/stdc++.h>
using namespace std;
int ans[5];string a,b,c,d;
int ts(string x)
{
	int num=0;
	for(int i=0;i<x.size();i++)
		if(x[i]-'0'>=0&&x[i]-'0'<10)
			num=num*10+int(x[i]-'0');
	return num;
}
int main()
{
 	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(ts(a)==ts(c))
	{
		ans[1]=1;
		if(ts(b)==ts(d))
		{
			ans[2]=1;
			if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')||(b[2]!='D'&&b[2]!='F'&&d[2]!='D'&&d[2]!='F'))
			{
				ans[3]=1;
				if(abs(int(b[2]-d[2]))==1)
					ans[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++)
		printf("%d",ans[i]);
 	return 0;
}
