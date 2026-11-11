#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int c,t;
int main()
{
   freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
   cin>>c>>t;
   while(t--){
	  int n;
	  long long d,x[2000010];
	  cin>>n>>d;
	  for(int i=1;i<=n;i++){
		  cin>>x[i];
	   }
	  long long f=x[2]-x[1];
	  if(d<=f ||  d/f==1){
		 cout<<0<<endl;
		 continue;
	   }
	   else{
		  long long k=d/f;
		  if(k>=n-1){
			  cout<<0<<endl;
			  continue;
		  }
		  else
		    if(2*k>=n){
			   cout<<(n-k)*n-n*(n-1)/2+k*(k-1)/2<<endl;
			    continue;  
	       }
	       else{
			 cout<<(k-1)*n-(2*k-1)*k+k*(k-1)/2<<endl;
			 continue;  
			}
	   } 
    }
   return 0;
}
