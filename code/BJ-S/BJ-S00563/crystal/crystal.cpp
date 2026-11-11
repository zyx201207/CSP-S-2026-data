#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N];
inline int fnd(int id){
    int l=1,r=id-1,pos=id;
    while(l<=r){
        int mid=(l+r)>>1;
        if(m+(s[id-1]-s[mid-1])>=a[id]*(id-mid))pos=mid,r=mid-1;
        else l=mid+1;
    }
    return pos;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int pos=fnd(i);
        ans=max(ans,i-pos+1);
    }
    cout<<ans<<'\n';
    return 0;
}