#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int pre[500005];
int find(int pos){
    int l=1,r=pos,ans;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[pos]*(pos-mid+1)-(pre[pos]-pre[mid-1])<=m) ans=mid,r=mid-1;
        else l=mid+1;
    }
    return ans;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=find(i);
        ans=max(ans,i-x+1);
    }
    cout<<ans;
}