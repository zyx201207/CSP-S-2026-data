#include <bits/stdc++.h>
using namespace std;
long long m,n,a[100000],sum=0,mi=0,s=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<n;j++){
           if(a[j]>a[j+1]){
              long long t=a[j];
              a[j]=a[j+1];
              a[j+1]=t;
           }
       }
    }

    mi=a[n];
    for(long long i=n;i>1;i--){
        for(long long j=1;j<=n-i+1;j++){
            sum=a[j+i-1]*(i-1);
            for(long long k=j;k<j+i-1;k++){
                sum-=a[k];
            }
            if(sum==m){
                cout<<i;
                return 0;
            }
            if(sum-m<mi){
                    mi=sum-m;
                    s=i;
            }
        }
    }
    cout<<s;
    return 0;
}
