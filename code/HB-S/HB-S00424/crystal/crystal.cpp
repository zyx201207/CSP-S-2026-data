#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,fl=1,ff=1,s[500005];
int get(int x){
    int l=1,r=x-1,re;
    while(l<=r){
        int mid=l+r>>1;
        if((x-mid)*a[x]-(s[x-1]-s[mid-1])<=m)r=mid-1,re=mid;
        else l=mid+1;
    }
    return max(re,1ll);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        ans=max(ans,i-get(i)+1);
    }
    cout<<ans<<'\n';
    return 0;
}