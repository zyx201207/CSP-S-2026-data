#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
   int n,m;
   cin>>n>>m;
   int a[n];
   int b;
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   for(int i=0;i<n;i++){
      a[i]%=2;
      cout<<a[i];
   }
   return 0;
}
