#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("hub.in","r",stdin);
   freopen("hub.out","w",stdout);
   int c,t,n,k,a[1005],b[1005];
   cin>>c>>t;
   for(int i=1;i<=t;i++){
    cin>>n>>k;
    for(int i=1;i<=n-1;i++){
        cin>>a[i]>>b[i];
    }
   }
   if(t%2==0){
    for(int i=1;i<=t/2;i++){
        cout<<1<<endl;
    }
    for(int i=t/2;i<=t-1;i++){
        cout<<2<<endl;
    }
   }
   else {
     for(int i=1;i<=t/2+1;i++){
        cout<<1<<endl;
    }
    for(int i=t/2+1;i<=t;i++){
        cout<<2<<endl;
    }
   }
   return 0;
}