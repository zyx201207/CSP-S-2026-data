#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10,Log=20;
int n,m,a[maxn],ans,st[maxn][Log],l[maxn];
bool check(int x){
    int sum=0,need=LLONG_MAX;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(i<x)continue;
        sum-=a[i-x];
        need=min(need,a[i]*x-sum);
    }
    return need<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=2;i<=n;i++)
        l[i]=l[i>>1]+1;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<=r){
        int mid=l+((r-l)>>1);
        if(check(mid))
            ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
