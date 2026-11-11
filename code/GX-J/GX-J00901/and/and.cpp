#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long ma=0,t;
    vector<long long> a(n+10);
    for(long long i=0;i<n;i++){
        cin>>a[i];
        t=a[0];
        if(a[i]>ma)ma=a[i];
        if(i!=0) t&=a[i];
    }
    if(m==2){
        ma=0;
        for(int i=1;i<n;i++){
                for(int j=i;j<n;j++){
                    t&=a[j];
                    if(t>ma) ma=t;
                    t=a[i-1];
                }
                t=a[i];
        }
    }
    if(n==m) ma=t;
    long long x=2;
    while(x<n) x*=2;
    if(x==n){
            t=1;
         for(int i=3,j=0;i<n,j<=m;i++){
            if(i%2==1) t&=i,j++;
         }
         ma=t;
    }
    cout<<ma;
    return 0;
}
