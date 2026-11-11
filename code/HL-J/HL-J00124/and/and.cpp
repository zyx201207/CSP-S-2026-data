#include <bits/stdc++.h>
using namespace std;
long long a[200010];
long long p[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long maxn1=0,maxn2=0,maxn3=0,maxn4=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn1=max(maxn1,a[i]);//max

        if(a[i]^0==a[i])
            maxn2=max(maxn2,a[i]);//15 31 ...
        }
        long long k=0,k1=0;

    for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            k++;
            if(a[i]^0==a[i]){
            if(a[j]>=a[i]){
                maxn3=a[i];
                continue;
            }
            else {
                maxn3=a[j];
                continue;
            }
        }
        long long x1=a[i],x2=a[j];
            p[k]=x1&x2;
            maxn3=max(maxn3,p[k]);//m=2 max
        }
    }
    if(m==1){
    cout<<maxn1;
    }
    else if(m==2){
        cout<<maxn3;
    }
    else if(m=3){
    maxn3=0;
    for(long long i=1;i<=k;i++){
        for(long long j=i+1;j<=k;j++){
            k1++;
            if(a[i]^0==a[i]&&a[i]!=0){
            if(a[j]>=a[i]){
                maxn3=a[i];
                continue;
            }
            else {
                maxn3=a[j];
                continue;
            }
        }
        long long x1=a[i],x2=a[j];
            p[k1]=x1&x2;
            maxn3=max(maxn3,p[k1]);//m=2 max
        }
    }
    cout<<maxn3;
    }
    else{
        cout<<1;
    }
    /*int x=3&5;
    cout<<x;*/
    return 0;
}

