#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,m,a[maxn],pre[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i-1,res=1e18;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid)-pre[i-1]+pre[mid-1]<=m)res=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans;
    return 0;
}