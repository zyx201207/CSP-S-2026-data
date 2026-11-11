#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001];
inline bool check(long long x){
    for(long long i=1;i+x-1<=n;++i){
        if(a[i+x-1]*x-(b[i+x-1]-b[i-1])<=m){
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;++i){
        b[i]=b[i-1]+a[i];
    }
    long long l=1,r=n,ans=0;
    while(l<=r){
        long long mid=l+((r-l)>>1);
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
