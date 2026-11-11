#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[10005],b[10005],cc[10005],x[1005],y[1005];
int main(){
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
   cin>>c>>n>>m>>d>>q;

   for(int i=1;i<=m;i++){
    cin>>a[i];
   }
   int k;
   cin>>k;
   for(int i=1;i<=2*k;i++){
    cin>>b[i];
   }
   int kk;
   cin>>kk;
   for(int i=1;i<=2*kk;i++){
    cin>>cc[i];
   }
   for(int i=1;i<=n;i++){
    cin>>x[i]>>y[i];
   }
   for(int i=1;i<=n;i++){
        int cnt=0;
    if(y[i]-x[i]==1){
        cnt+=a[x[i]];
        cnt+=b[y[i]];
        cnt+=b[y[i]*2];
        cnt+=a[y[i]];
        cout<<cnt<<endl;
    }
    else{
        cnt+=a[x[i]];
        cnt+=a[y[i]];
        cnt+=b[y[i]-x[i]];
        cnt+=b[y[i]+x[i]];
        cnt+=cc[y[i]-x[i]];
        cnt+=cc[y[i]+x[i]];
        cout<<cnt<<endl;
    }
   }
   return 0;
}
