#include<bits/stdc++.h>
#define int long long
#define fu1(i,n,k) for(int i=1;i<=n;i+=k)
#define fu0(i,n,k) for(int i=0;i<n,i+=k)
#define fd1(i,n,k) for(int i=n;i>=1;i-=k)
#define fd0(i,n,k) for(int i=n-1;i>0;i-=k)
#define pb push_back
#define ps push
#define lb(x) (x&(x-1))
using namespace std;
const int N=5e5+10;
int n,m,sum[N],a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    fu1(i,n,1) cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    fu1(i,n,1){
        sum[i]=sum[i-1]+a[i];
        int l=1,r=i;
        while(l<=r){
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid-1,ans=max(ans,i-mid+1);
            else l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
