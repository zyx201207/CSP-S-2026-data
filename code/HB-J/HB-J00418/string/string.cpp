#include<bits/stdc++.h>
using namespace std;

struct MM{
    long long a;
    string s;
}b[11111111];
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   long long n;
   bool f;
   cin>>n;
   for(int i=1;i<=n;i++){
    cin>>b[i].a>>b[i].s;
   }
   long long sum=0;
   for(int i=1;i<=n;i++){
    sum+=b[i].a;
   }
   long long j=sum/2;
   for(int i=1;i<=n;i++){
    if(b[i].s==b[i+1].s){
        f=0;
    }
    else{
        f=1;
    }
   }
   if(f==0){
    cout<<"0";
   }
   else{
    cout<<j;
   }
   return 0;
}
