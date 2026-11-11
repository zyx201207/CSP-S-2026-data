#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define int long long
int n,m,a[maxn],sum[maxn],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=((l+r)>>1);
            if((a[i]*(i-mid))-(sum[i-1]-sum[mid-1])>m){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}