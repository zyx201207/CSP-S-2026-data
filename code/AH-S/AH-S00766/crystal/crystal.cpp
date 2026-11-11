#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+325;
int n,m,a[N],sum[N],ans;
bool check(int p,int r){
    int t=sum[r]-sum[p-1];
    int res=a[r]*(r-p+1)-t;
    return res<=m;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=l+r>>1;
            if(check(mid,i)) r=mid;
            else l=mid+1;
        }
        ans=max(i-l+1,ans);
    }
    cout<<ans;
    return 0;
}
