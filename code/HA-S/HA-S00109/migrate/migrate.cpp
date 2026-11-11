#include<bits/stdc++.h>
using namespace std;
long long x[2000020];

int main()
{
	freopen("migrate.in ","r",stdin);
	freopen("migrate.out ","w",stdout);
	int cc,tt;
    scanf("%d%d",&cc,&tt);
    for(int yy=1;yy<=tt;yy++)
    {	
    	int n,d;
    	cin>>n>>d;
    	int a[n+1][n+1];
    	memset(a,0,sizeof(a));
    	for(int y=1;y<=n;y++)
    	scanf("%d",&x[y]);
    	if(cc==11||cc==12)
    	{
    		int c=x[2]-x[1];
    		int num=d/c;
    	
    	
    		for(int y=1;y<=n;y++)
    	{
    		for(int u=y+1;u<=n;u++)
    		{
    			if(u-y<=num)
    			a[y][u]=1;
    			else
    			if((u-y)%num==0)
    			a[y][u]=1;
    			else
    			{
    				int bz=(u-y)/num+1;
    				for(int v=u-num;v<=u;v++)
    				if(a[y][v]+1==bz)
    				 a[y][u]++;
				}
			}
		}//cout<<1;
		int ans=0;
    		for(int y=1;y<=n;y++)
    		for(int u=y+1;u<=n;u++)
    		if(a[y][u]==2)
    		ans++;
    		cout<<ans/2<<endl;
    		
		}
	}
	return 0;
}
//405		C:\Users\ADMINI~1\AppData\Local\Temp\ccIioVAw.s	Error: value of 00000746afa6132e too large for field of 4 bytes at 000000000000036e
