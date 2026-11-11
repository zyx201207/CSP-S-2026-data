#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long 
const int N=5e5+5;
ll n,m,a[N],s[N];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];int ans=0;
    for(int i=1;i<=n;i++) {
        int l=1,r=i,mid;
        while(l<r) {
            mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)r=mid;
            else l=mid+1;
        }ans=max(ans,i-l+1);
    }cout<<ans;
    return 0;
}
/*
1000000000000
*/