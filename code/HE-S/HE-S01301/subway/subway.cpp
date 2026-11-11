#include<bits/stdc++.h>
using namespace std;
int main()
freopen("subway.in",'r',stdin);
freopen("subway.out",'w',stdout);
{
	int n,m,a,b,c,d,e,x;
	cin>>n>>m>>a>>b>>c>>d>>e;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a?=b&&a?=c&&a?=d&&a?=e&&a?=x&&b?=c&&b?=d&&b?=e&&b?=x&&c?=d&&c?=e&&c?=x&&d?=e&&d?=x&&e?=x)
			{
				int sun1=a*10000+b*1000+c*100+d*10+e;
				int sun2=e*10000+d*1000+c*100+b*10+a;
				if(sun1*x==sun2)
				cout<<a<<b<<c<<d<<e<<x<<endl;
			}
			
		}
	}
} 
