#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50000000000],sum,b[50000000000],c[500000][500000],max1=0;
int main(){
ifstream fin("card.in");
ofstream fout("card.out");
fin>>n>>m;
for(int i=1;i<=n;i++){
a[i]=0;
b[i]=0;
  for(int j=1;j<=n;j++){
	c[i][j]=0;
  }
}
for(int i=1;i<=n;i++){
if(a[i]>max1)
max1=a[i];
}
for(int i=1;i<=n;i++){
fin>>a[i];
}
for(int i=1;i<=n;i++){
  for(int j=i;j<=n;j++){
    for(int z=1;z<=j;z++){
      if(c[i][z]==a[j]){
      c[i][z]=a[j];
        if(z!=j){
          for(int x=z+1;x<=j;x++){
          c[i][x]=0;
          }
        }
      }
    }
     c[i][j]=a[j];
   }
  for(int j=1;j<=n;j++){
    for(int z=1;z<=j;z++){
      if(c[i][z]==a[j]){
      b[a[j]]++;
      }
    }
  }
}
for(int i=1;i<=max1;i++){
fout<<b[i];
}
return 0;
}
