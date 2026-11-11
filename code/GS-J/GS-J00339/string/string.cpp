#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    bool w=0;
	long long n,c[100000];
	string a,g;
	 char ans;
	 cin>>n;
	 for(int i=0;i<n;i++) 
	  {
	    cin>>c[i]>>a[i];
	    
      }
	  for(int i=0;i<n;i++) 
	  {
	   ans=a[i];
	   for(int j=0;j<i;j++) 
		{
		   
		   if(ans==a[j])
	     {  
	    	 w=1;
	     }
	      else
         {    
          w=0;
	     }
	    }
	} 
	    if(w==1)
	  {
	  	cout<<"0";
      }	 
	          
  














}
 
	

	
	
	
	

