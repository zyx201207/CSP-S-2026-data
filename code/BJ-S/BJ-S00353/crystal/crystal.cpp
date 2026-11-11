#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,ans,l,r,mid;
int a[MAXN],sum[MAXN];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        l=1,r=i;
        while(l<=r){
            mid=(l+r)/2;
            if((i-mid+1)*a[i]-sum[i]+sum[mid-1]>m){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
