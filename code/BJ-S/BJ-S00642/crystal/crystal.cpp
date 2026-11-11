#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[500005];
long long sum[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int r=1,maxn=0;
    for(int i=1;i<=n;i++){
        while(r<i && a[i]*(i-r+1)-(sum[i]-sum[r-1])>m){
            r++;
        }
        // cout<<r<<'\n';
        maxn=max(maxn,i-r+1);
    }
    cout<<maxn;
    return 0;
}