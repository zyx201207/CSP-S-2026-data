#include<bits/stdc++.h>
using namespace std;
long long n,m=0,ans=0;
char a[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
   for(int i=1;i<=n;i++){
       long long k;
       char x;
       cin>>k>>x;
       while(k--){
           a[++m]=x;
       }
   }
  // for(int i=1;i<=m;i++)cout<<a[i];
   for(int i=1;i<=m/2;i++){
       if(a[i]!=a[m-i+1])ans++;
   }
   cout<<ans;
    return 0;
}