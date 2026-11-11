#include<bits/stdc++.h>
using namespace std;
long long c,t,n,s[200008],g,d,a[200008];
int fff(long long x,long long y,long long z){
	if(x==y)
	{
		int j=0;
		for(int i=1;i<z;i++)
		{
			if(s[i]>0) j=1;
		}
		if(j==0)
		s[z]++;
		return 0;
	}
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]<=d)
		{
			fff(i,y,z+1);
		}
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
   cin>>c>>t;
   for(int k=1;k<=t;k++)
   {
   	    cin>>n>>d;
   	    for(int j=1;j<=n;j++)
   	    {
   	 	    cin>>a[j];
	    }
	    for(int i=1;i<=n;i++)
	    {
	    	for(int j=i+1;j<=n;j++)
	    	{
	    		fff(i,j,0);
	    		for(int l=1;l<=1000;l++){
	    	    	if(s[l]==2)
	    		    {
	    		    	g++;
			    	}
			    	if(s[l]>0)
			    	{
			    		break;
					}
			   }
			   for(int j=1;j<=1000;j++)
			{
				s[j]=0;
			}
			}
		}
		cout<<g<<endl;
		g=0;
   }
	return 0;
}
