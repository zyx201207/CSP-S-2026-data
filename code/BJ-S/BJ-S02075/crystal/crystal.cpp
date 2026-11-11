#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int a[N],n,m,pre[N];

inline int check(int l,int r){
    return a[r]*(r-l+1)-(pre[r]-pre[l-1])<=m;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //freopen("crystal1.in","r",stdin);
    //freopen("crystal1.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    int ans=1;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid,i))r=mid;
            else l=mid+1;
        }ans=max(ans,i-l+1);
    }cout<<ans<<'\n';
    return 0;
}
