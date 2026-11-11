#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
   int a[10005],n,y=1,m=0,x=0;
   char b[1005],c[10005];
   cin>>n;
   for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
    m+=a[i];
   }
   for(int i=1;i<=m;i++){
      for(int j=1;j<=a[i];j++){
        c[y]=b[i];
        y++;
      }
   }
   int h=m%2;
   if(h==1){
    for(int i=1;i<=m/2;i++){
        if(c[i]!=c[m-i+1]){
            x++;

        }
      }
   }
   else{
    for(int i=1;i<=m/2;i++){
        if(c[i]!=c[m-i]){
            x++;
        }
      }
   }
cout<<x;
return 0;
}
