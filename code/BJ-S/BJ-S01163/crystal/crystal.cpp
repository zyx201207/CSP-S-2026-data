#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],s[N];
bool check(int mid){
    for(int i=1;i<=n-mid+1;i++){
        if(mid*a[i+mid-1]-(s[i+mid-1]-s[i-1])<=m)return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
