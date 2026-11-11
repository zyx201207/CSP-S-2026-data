#include<bits/stdc++.h>
using namespace std;
int a[200005];
int c[200005];
 int n,m;
  int ans=-1;
int b=a[1];
int d=c[1];
void dfs(int k){
   if(k==n+1){
    for(int i=2;i<n;i++){
         d=c[i]&c[i+1];
         if(d>=ans) ans=d;
    }return;
  }
   else{
    c[k]=a[1];
    dfs(k+1);
    return;
   }
}


int main(){

freopen("and.in","r",stdin);
freopen("and.out","w",stdout);

  cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }

  if(n==m){
    for(int i=2;i<n;i++){
       b=a[i]&a[i+1] ;
    }
    cout<<b;
  }
  else{
   dfs(m);
cout<<d;
    }




   return 0;
}
