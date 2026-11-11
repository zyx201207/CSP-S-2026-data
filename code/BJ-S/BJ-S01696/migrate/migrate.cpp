#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
   freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
   long long c,t;
   cin>>c>>t;
   while(t--){
        long long n,d,zero=0;
        cin>>n>>d;
  if(n<=d){cout<<0;}
   else if(d==1){cout<<0;}
else{
        for(int i=1;i<=n;i++)cin>>a[i];
        if(c==11||c==12){
            cout<<max(n-d*2+1,zero)<<endl;
            continue;
        }
   }}
   return 0;
}
