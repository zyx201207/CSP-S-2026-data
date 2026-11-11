#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    int f=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i!=1&&a[i]!=a[i-1]){
            f=1;
        }

    }
    sort(a+1,a+n+1);
    if(f==0){
        cout<<n;
        return 0;
    }
    long long mx=INT_MIN;
    for(long long i=1;i<=n;i++){
        long long s=0;
        for(long long j=1;j<=i;j++){
            s+=a[i]-a[j];
        }
        if(s<=m){
            mx=max(mx,i);
        }
    }
    if(mx==INT_MIN){
        mx=INT_MIN;
        for(long long i=1;i<=n;i++){
            long long s=0;
            for(long long j=i+1;j<=n;j++){
                s+=a[j]-a[i];
            }
            if(s<=m){
                mx=max(mx,n-i+1);
            }
        }
    }


    printf("%lld",mx);


    return 0;
}
//1 2 3 4 5

