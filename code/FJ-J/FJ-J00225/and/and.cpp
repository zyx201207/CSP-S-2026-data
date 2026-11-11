#include<bits/stdc++.h>
using namespace std;
int a[200005];	
int b[10000005];
int ejz(int x)
{
	if(x<2)return x;
	else return x%2+ejz(x/2)*10;
}
int l;
int main()
{
	freopen("and.in.txt","r",stdin);
	freopen("and.out.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=ejz(a[i]);
	
	}

	for(int i=1;i<=n;i++)
	{
	    for(int j=i+1;j<=n;j++)
	    {
	    	int ws=0;
			int ans=0;
			int x=a[i],y=a[j];
	    	while(min(x,y)!=0)
	    	{
	    		
	    		int g1=x%10;
	    		int g2=y%10;
	    		if(g1==g2)
	    		{
	    		    b[ws]=1;
				}
				else b[ws]=0;
				ws++;
				x/=10;
				y/=10;
			}
			for(int i=0;i<ws;i++)
			{
				ans+=b[i]*pow(2,i);
			}
			l=max(ans,l);
		}
	}
	cout<<l;
	return 0;
 } 
