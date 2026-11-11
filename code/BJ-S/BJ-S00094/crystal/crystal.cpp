#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long  n,m;
bool cmp(int a,int b){
    return a>b;
}
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   cin>>n>>m;

   for(int i=1;i<=n;i++){
    cin>>a[i];
   }
   if(m==0){
        int b[10005];
    for(int i=1;i<=n;i++){
        b[a[i]]+=1;
    }
    int zhi=0;
   for(int i=1;i<=n;i++){
    zhi=max(zhi,b[i]);
   }
   cout<<zhi;
   return 0;
   }
   int zui=0;
   sort(a+1,a+n+1,cmp);
   for(int i=1;i<=n;i++){
   int ji=0;
    int cun=m;
    for(int j=i;j<=n+1;j++){
            if(cun<=0){
            zui=max(zui,ji);
            break;

        }
        cun=cun-a[i]+a[j];
            ji=ji+1;
    }
   }
   if(zui==0){
    cout<<n;
      return 0;
   }

   cout<<zui;
   return 0;
}