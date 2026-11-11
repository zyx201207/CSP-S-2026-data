#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],ans;
char c[500005];
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;)
	{
		if(c[i]==c[j])
		{
		  if(a[i]>a[j])
		  {
		   a[i]-=a[j];
		   j--;	
		  }	
		  else
		  if(a[i]<a[j])
		  {
		  	a[j]-=a[i];
		  	i++;
		  }
		  else
		  {
		  	i++,j--;
		  }
		}
		else
		{
		  	if(a[i]>=a[j])
	      {
	       ans+=a[j];
	       a[i]-=a[j];
	       a[j]=0;
	       j--;	
	      }
	       else if(c[i]!=c[j])
	      {
	     	ans+=a[i];
	    	a[j]-=a[i];
	    	a[i]=0;
	    	i++;
	       }
	   }
	 
	 //cout<<i<<" "<<j<<endl;	
	} 
	cout<<ans;
return 0;
}
