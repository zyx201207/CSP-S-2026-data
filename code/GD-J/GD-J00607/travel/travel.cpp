#include<bits/stdc++.h>
using namespace std;
int n;
int a,b;
char c[3],d[3];
bool ans[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c[0]>>c[1]>>c[2]>>b>>d[0]>>d[1]>>d[2];
	int e=(c[0]-'0')*10+c[1]-'0',f=(d[0]-'0')*10+d[1]-'0';
	if(a==b) 
	{
		ans[0]=1;
		if(e==f) 
		{
			ans[1]=1;
			if(c[2]-'A'<=2&&d[2]-'A'<=2) 
			{
				ans[2]=1;
				if(abs(c[2]-d[2])==1) ans[3]=1;
			}
			if(c[2]-'A'>2&&d[2]-'A'>2) 
			{
				ans[2]=1;
				if(abs(c[2]-d[2])==1) ans[3]=1;
			}
		}
//		if(c[2]-'A'<=2&&d[2]-'A'<=2) 
//		{
//			if(abs(e-f)==1)
//			{
//				if(c[2]==d[2]) ans[3]=1;
//			}
//		}
//		if(c[2]-'A'>2&&d[2]-'A'>2) 
//		{
//			if(abs(e-f)==1)
//			{
//				if(c[2]==d[2]) ans[3]=1;
//			}
//		}
	}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
} 
