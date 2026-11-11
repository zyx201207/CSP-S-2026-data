#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
   long long n,m,cnt=0;
   long long a[1000];
   long long l;
   cin>>n>>m;
   for(int i=1;i<=n;i++){
    cin>>a[i];
    l=max(a[1],a[i]);
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++){
        if(a[i]++==l){
            cnt++;
            break;
        }
       }
   }
   cout<<cnt+1;
    return 0;
}


