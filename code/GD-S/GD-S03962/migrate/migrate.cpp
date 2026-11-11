#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],ans,answer,sum=1e9,minsum=1e9,sumi=0;
void dfs(int x,int y,int sum)
{
	if(x==y)
	{
		if(sum==minsum) sumi++,ans++;
		else if(sum<minsum) minsum=sum,sumi=ans=1;
	    return ;
	}
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]<=d)
		{
			dfs(i,y,sum+1);
		}
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		answer=0;
        cin>>n>>d;
        int f=0;
        for(int i=1;i<=n;i++)
		{
		    cin>>a[i];	
		    if(i>2)
		    {
		    	if(a[i]-a[i-1]!=a[i-1]-a[i-2]) f=1;
			}
		}
        if(!f&&d==a[2]-a[1])
        {
        	cout<<"0\n";
        	continue;
		}
        for(int i=1;i<n;i++)
        {
        	for(int j=i+1;j<=n;j++)
        	{
			    sum=0,minsum=1e9,sumi=0;
        		dfs(i,j,0);
        		if(ans==2) ans=0,answer++;
			}
		}
		cout<<answer<<"\n";
	}
	return 0;
}
