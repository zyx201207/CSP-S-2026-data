#include<bits/stdc++.h>
using namespace std;

int main(){
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
   long long n,m;

   cin>>n>>m;
   long long a[11111111];
   for(int i=1;i<=n;i++){
    cin>>a[i];
   }
   sort(a,a+1,a+n+1);
   long long tp;
   for(int i=1;i<=n;i++){
    tp=a[i-m+1];
   }
   cout<<tp;
   return 0;
}
