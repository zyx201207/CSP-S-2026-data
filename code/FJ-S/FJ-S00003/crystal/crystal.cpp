#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,ans;
ll m,a[N],s[N];
bool check(int mid){
    ll sum=1e18+5;
    for(int i=1;i+mid-1<=n;i++) sum=min(sum,1ll*mid*a[i+mid-1]-(s[i+mid-1]-s[i-1]));
    return sum<=m;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)) ans=max(ans,mid),l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<'\n';
}