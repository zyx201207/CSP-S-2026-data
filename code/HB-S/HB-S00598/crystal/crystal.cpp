#include<bits/stdc++.h>
//100pts
using namespace std;

typedef long long ll;
typedef __int128 lll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int N=6e5+10;
ll a[N];
ll sum[N];
int n;
ll m;
int ans=0;
inline bool check(int l,int r){
    ll del=(a[r]*(r-l+1))-(sum[r]-sum[l-1]);
    return (del<=m);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l,r,mid;
    for(int i=1;i<=n;i++){
        l=1,r=i;
        while(l<r){
            mid=(l+r)>>1;
            if(check(mid,i)){
                r=mid;
            }
            else l=mid+1;
        }
        if(check(l,i))ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
/*

*/