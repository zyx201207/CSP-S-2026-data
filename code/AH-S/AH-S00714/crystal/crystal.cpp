#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],s[N];
ll n,m;
bool check(int mid){
    for(int i=mid;i<=n;i++){
        if(a[i]*mid-s[i]+s[i-mid]<=m)return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int l=0,r=n,mid,ans=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1,ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
