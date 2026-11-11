#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,s[N],a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int res=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        int l=1,r=i-1,mid,ans=i;
        while(l<=r){
            mid=(l+r)/2;
            if((i-mid+1)*a[i]-s[i]+s[mid-1]<=m){
                r=mid-1;
                ans=mid;
            }else l=mid+1;
        }
        res=max(res,i-ans+1);
    }
    cout<<res;
    return 0;
}