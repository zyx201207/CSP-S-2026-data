#include<bits/stdc++.h>
using namespace std;
long long  a[1005];
int ji;
bool cmp(int a,int b){
return a>b;
}
int main(){
     freopen("and.in","r",stdin);
     freopen("and.out","w",stdout);
     int n,m;
     cin>>n>>m;

     for(int i=1;i<=n;i++){
        cin>>a[i];
     }

     sort(a+1,a+n+1,cmp);
     int zong[1005];
     for(int i=1;i<=m;i++){
        long long c[1005];
        ji=0;
        while(a[i]!=0){
        ji++;
        c[ji]=a[i]%2;
        a[i]=a[i]/2;
    }
   for(int j=ji;j>=1;j--){
    zong[j]+=c[j];
   }
     }

     int cnt=0;

     for(int i=ji;i>=1;i--){
        if(zong[i]==m){
            cnt+=1*pow(2,i-1);
        }
     }
     cout<<cnt;
    return 0;
}
