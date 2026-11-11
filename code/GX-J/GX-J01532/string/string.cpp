#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
char a[10005];
int c[10005];
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   long long b;
   cin>>a;
   for(int i=0;i<=b;i++){
   cin>>c[i]>>a[i];
   }
   int r;
   for(int q=0;q<=b;q++){
   if(a[i]==a[i+1])r++;
   else break;}
   int g;
   for(int t=b;t>=b-r;t--){
   g+=c[t]}
   cout<<g<<endl;
   return 0;}
