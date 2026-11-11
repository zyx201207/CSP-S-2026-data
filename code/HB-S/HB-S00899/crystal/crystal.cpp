#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000005];
__int128 s[1000005];
bool check(int l,int r){
    return (__int128)((__int128)r-(__int128)l)*(__int128)a[r]-(__int128)(s[r-1]-s[l-1])<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    __int128 sum=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    long long ans=1;
    for(long long i=1;i<=n;i++){
        long long l=1,r=i;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,i)) r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-r);
    }
    cout<<ans;
    return 0;
}
