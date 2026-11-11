#include <bits/stdc++.h>
using namespace std;
long long m,n,a[50005],b[50005],maxn=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<n;i++){
        b[i+1]=b[i]+a[i];
    }
    for(long long i=2;i<=n;i++){
        for(long long j=i;j<=n;j++){
            long long k=j-i+1,sum=0;
            if(i*a[j]-(b[k+i]-b[k-1])<=m&&maxn<i){
                maxn=i;
                break;
            }
        }
    }
    cout<<maxn;
    return 0;
}
