#include <bits/stdc++.h>
using namespace std;
int m,n,a[10000000];
int yu(long long int b1,long long int b2){
    int c1[1000],c2[1000];
    string e;
    for(int i=1;i<=log2(b1);i++){
        c1[i]=b1%2;
        b1/2;
        if(b1==0){
            break;
        }
    }
    for(int i=1;i<=log2(b2);i++){
        c2[i]=b2%2;
        b2/2;
        if(b2==0){
            break;
        }
    }
    for(int i=max(log2(b1),log2(b2));i>0;i++){
        if(c1[i]==c2[i]){
            e[i]=1;
        }else {
            e[i]=0;
        }
    }
    int sum=0,t=1;
    for(int i=0;i<=e.length();i++){
        for(int i=0;i<=n;i++){
            t=t*2;
        }
        sum+=e[i]*t;
    }
    return sum;
}
int main(){
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
    cin>>a[i];
   }
   int maxx=0;
   for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            int h=yu(i,j);
            if(h>maxx){
                maxx=h;
            }
        }
   }
   cout<<maxx;
   return 0;
}
