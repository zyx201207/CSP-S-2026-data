#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int a[N],n,m,sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int ans=0;
    for (int i=1;i<=n;i++){
        int j;
        int l=i,r=n,mid;
        while (l<=r){
            mid=l+r>>1;
            if (a[mid]*(mid-i)-sum[mid-1]+sum[i-1]<=m)j=mid,l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans;
    return 0;
}
