#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool flag1=0,flag2=0,flag3=0,flag4=0;
	if(a==c)
	{
		flag1=1;
		if(b[0]==d[0]&&b[1]==d[1])	
		{
			flag2=1;
			char tt1=b[2],tt2=d[2];
			bool k11=(tt1<='C');
			bool k22=(tt2<='C');
			if(k11==k22)
			{
				flag3=1;
				if(abs(tt1-tt2)==1)flag4=1;
			}
			
		}
	}
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
} 
