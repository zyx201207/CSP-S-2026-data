#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],p[maxn],ans;
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid,anss=0;
        while(l<=r){
            mid=(l+r)>>1;
            int cur=a[i]*mid-(p[i]-p[i-mid]);
            if(cur<=m)anss=mid,l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,anss);
    }
    cout<<ans;
    return 0;
}
