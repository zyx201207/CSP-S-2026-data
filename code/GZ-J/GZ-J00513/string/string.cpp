//GZ-J00513 兴义市弘毅中学 李宇轩 
#include<bits/stdc++.h>
using namespace std;
long long a,sam=0;

struct s{
	long long m;
	char n;
}j[2000050];

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
scanf("%lld",&a);
long long sum=0;
	for(long long i=1;i<=a;i++){
	getchar();
		scanf("%lld",&j[i].m);
		sum+=j[i].m;
		getchar();
		scanf("%c",&j[i].n);
	}
	long long x=0,y=0;
	if(sum%2==0){
	while(x!=a/2&&y!=a/2){
		if(j[1+x].n!=j[a-y].n){
	sam+=min(j[1+x].m,j[a-y].m);
	if(j[1+x].m==j[a-y].m){
				x++;
				y++;
				continue;
			}
             if(min(j[1+x].m,j[a-y].m)==j[1+x].m){
           	 j[a-y].m=max(j[1+x].m,j[a-y].m)-min(j[1+x].m,j[a-y].m);
  	       x++;
         }
            else{
  	        j[1+x].m=max(j[1+x].m,j[a-y].m)-min(j[1+x].m,j[a-y].m);
  	         y++;
               } 
	}
	else {
		if(j[1+x].m==j[a-y].m){
				x++;
				y++;
				continue;
			}
	        if(min(j[1+x].m,j[a-y].m)==j[1+x].m){
  	     j[a-y].m=max(j[1+x].m,j[a-y].m)-min(j[1+x].m,j[a-y].m);
          	x++;
       }
             else{
  	        j[1+x].m=max(j[1+x].m,j[a-y].m)-min(j[1+x].m,j[a-y].m);
      	       y++;
          } 
      	}	
                           }   
}
  else {
  	while(x!=a/2+2&&y!=a/2+2){
		if(j[1+x].n!=j[a-y].n){
			sam+=min(j[1+x].m,j[a-y].m);
			if(j[1+x].m==j[a-y].m){
				x++;
				y++;
				continue;
			}
              if(min(j[1+x].m,j[a-y].m)==j[1+x].m){
  	           j[a-y].m=max(j[1+x].m,j[a-y].m)-min(j[1+x].m,j[a-y].m);
  	          x++;
              }
               else{
  	          j[1+x].m=max(j[1+x].m,j[a-y].m)-min(j[1+x].m,j[a-y].m);
  	           y++;
                } 
	}
	     else {
	     	if(j[1+x].m==j[a-y].m){
				x++;
				y++;
				continue;
			}
	          if(min(j[1+x].m,j[a-y].m)==j[1+x].m){
  	           j[a-y].m=max(j[1+x].m,j[a-y].m)-min(j[1+x].m,j[a-y].m);
  	         x++;
            }
              else{
  	         j[1+x].m=max(j[1+x].m,j[a-y].m)-min(j[1+x].m,j[a-y].m);
  	        y++;
              } 
	        }
	                     }	
    }
  
	printf("%lld",sam); 
	return 0;
}
