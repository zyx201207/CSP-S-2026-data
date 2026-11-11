#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   int e=1,f=1,g=1,h=1,sum1=0,sum2=0;
   string a,b,c,d;
   cin>>a>>b>>c>>d;
   for(int i=0;i<2;i++){
	   if(a[i]!=c[i]){
		   e=0;
		   f=0;
		   g=0;
		   h=0;
		   cout<<e<<f<<g<<h;
		   return 0;
	     }
      }
   for(int i=0;i<2;i++){
       if(b[i]!=d[i]){
		   f=0;
		   g=0;
		   h=0;
		   cout<<e<<f<<g<<h;
		  return 0;
	     }
	   }
	if(b[2]>='A'&&b[2]<='C'){
		sum1=1;
	  }else sum1=2;
	if(d[2]>='A'&&d[2]<='C'){
		sum2=1;
	  }else sum2=2;  	
	if(sum1!=sum2){
		  g=0;
		  h=0;
		  cout<<e<<f<<g<<h;
		  return 0;
	}
	if(b[2]-d[2]==1||d[2]-b[2]==1)h=1;
	  else h=0;
	 cout<<e<<f<<g<<h;            	     
   return 0;
}  
