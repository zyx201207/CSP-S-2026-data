#include<iostream>
using namespace std;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int m,n;
cin>>n>>m;
int a[n];
long long b[n];
b[0]=0;
for(int i=0;i<n;i++){
cin>>a[i];
}
sort(a,a+n);
for(int i=1;i<n;i++){
   b[i]=b[i-1]+i*(a[i]-a[i-1]);
   if(b[i]>m){
   cout<<i;
   break;
   }
}
fclose(stdin);
fclose(stdout);
return 0;
}
