#include<bits/stdc++.h>
using namespace std;
int a[200001],s[200001],p[200001];
int main() 
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) 
	{	
	  for(int j=1;j<=n;j++) 
	  {
		for(int k=1;k<=n;k++) 
	    {
			if(a[j]==p[k])
			{
			 for(int l=ans;l>=k;l--) 
	         {
			    p[l+1]=p[l];
			    ans--;
	         }	
		    }
		    else 
		    {
				p[ans++]=a[j];
			}
	    }
	  }
	   for(int k=1;k<=ans;k++) 
	   {
			s[p[k]]+=1;
	   }
	}
    for(int i=1;i<=m;i++)
    {
		cout<<s[i]<<" ";
	}
	return 0;
}
