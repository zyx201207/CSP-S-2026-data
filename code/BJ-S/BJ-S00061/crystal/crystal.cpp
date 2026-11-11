#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,m;
long long a[MAXN],sum[MAXN];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i];
        // cout<<sum[i]<<" ";
    }
    for(long long i=n;i;--i){
        if((i-1)*a[i]-sum[i-1]<=m){
            cout<<i<<"\n";
            return 0;
        }
    }
}