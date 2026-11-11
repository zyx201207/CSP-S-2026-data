#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
char kk[200009];
long long a[200009],n;
long long tt=0;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
cin>>a[i]>>kk[i];
for(int i=1,j=n;i<j;)
{
    if(kk[i]==kk[j])
    {
	  if(a[i]==a[j])
       {i++;
	     j--;}
       else
          if(a[i]>a[j])
           {a[i]=a[i]-a[j];
	          j--;
           }
	       else
	       {a[j]=a[j]-a[i];
	          i++;
	   	    }
	}
    else
    {tt+=min(a[i],a[j]);
          if(a[i]==a[j])
           {i++;
		   j--;
		   }
		else
         {
		  if(a[i]>=a[j])
	      {a[i]=a[i]-a[j];
	       j--;	   
		  }
		  else
		  {
		  a[j]=a[j]-a[i];	
			i++; 
		   }
         }
	}

	
}	
cout<<tt;	
	


return 0;	
}
