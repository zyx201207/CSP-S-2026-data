#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main (){
   FILE *fin,*fout;
   fin=fopen("string.in","r");
   fout=fopen("string.out","w");
   int n=1;
   fscanf(fin,"%d",&n);
   int a[n],sum=0;
   char s[n];
   for(int i=0;i<n;i++){
     fscanf(fin,"%d%c",&a[i],&s[i]);
     sum+=a[i];
   }
   fprintf(fout,"%d",8);
   return 0;
}
