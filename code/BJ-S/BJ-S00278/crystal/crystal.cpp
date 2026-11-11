#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+10;
int n;
ll m,a[maxn],s[maxn];
bool check(ll x){
    ll mn=1e18;
    for(int i=1;i+x-1<=n;i++){
        ll sum=s[i+x-1]-s[i-1];
        ll cnt=x*a[i+x-1];
        mn=min(mn,cnt-sum);
    }
    return mn<=m;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int L=1,R=n,ans=0;
    while(L<=R){
        int mid=L+R>>1;
        if(check(mid)){
            ans=mid;
            L=mid+1;
        }else{
            R=mid-1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
