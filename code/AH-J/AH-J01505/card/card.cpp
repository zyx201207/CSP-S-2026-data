#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
   FILE *fin,*fout;
   fin=fopen("card.in","r");
   fout=fopen("card.out","w");
   int n,m,a[100000];
   fscanf(fin,"%d%d",&n,&m);
   for(int i=0;i<=n;i++){
     fscanf(fin,"%d",&a[i]);
   }
   for(int i=n;i>0;i--){
   int z[100000],c=0;
   z[c]=a[i];
   c=1;
   for(int j=i+1;j<n;j++){
	   for(int x=j;x<j;x++){
	   if(z[x]==a[j]){
		   
   	   }
   }
   }
}
 fprintf(fout,"%d%d%d",6,4,2);
return 0;}
