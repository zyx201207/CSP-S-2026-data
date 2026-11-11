#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans;
ll a[500001],s[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >>n >>m;
    for(int i=1;i<=n;i++) cin >>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        ll l=1,r=i,cur=i;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid-1,cur=mid;
            else l=mid+1;
        }
        //cout <<cur <<" ";
        ans=max(ans,i-cur+1ll);
    }
    cout <<ans;
    return 0;
}
