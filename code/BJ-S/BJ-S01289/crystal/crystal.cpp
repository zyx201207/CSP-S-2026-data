#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+10;
ll a[N],s[N];
int check(int l,int r,ll m){
    int len=r-l+1;
    ll need=1ll*len*a[r]-(s[r]-s[l-1]);
    return need<=m;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    //freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    ll n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid,i,m))r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
//Oct31==Dec25?
/*
14.35
I often recall the past
30min做出T12然后剩下3.5h在做滚木

区完了

我是fw

何以NOIP
*/