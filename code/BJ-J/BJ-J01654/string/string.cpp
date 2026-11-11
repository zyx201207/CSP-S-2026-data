#include<bits/stdc++.h>
using namespace std;
int a,n,k,ans;
char b,m[500000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
   for(int i=1;i<=n;i++){
       cin>>a>>b;
       while(a--){
           k++;
           m[k]=b;
       }
   }
   for(int i=1;i<=k/2;i++){
       if(m[i]!=m[k-i+1])ans++;
   }
   cout<<ans;
    return 0;
}