#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m;
ll a[N],sum[N];
int ans;
ll f(int pos,int k){
    ll res=0,ret=0;
    res=sum[pos-1]-sum[pos-k-1];
    ret=k*a[pos]-res;
    return ret;
}
int find(int l,int r,int pos){
    int mid=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(f(pos,mid)<=m) l=mid+1;
        else r=mid-1;
    }
    return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];      
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;++i){
        ans=max(ans,find(1,i-1,i));
    }
    cout<<ans;
    return 0;
}