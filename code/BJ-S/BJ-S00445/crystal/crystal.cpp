#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn];
bool check(int x){
    int sum=0;
    for(int i=1;i<=x;i++)sum+=a[x]-a[i];
    if(sum<=m)return 1;
    for(int i=2;i+x-1<=n;i++){
        sum-=a[i+x-2]-a[i-1];
        sum+=x*(a[i+x-1]-a[i+x-2]);
        if(sum<=m)return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n,mid,res;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<res;
    return 0;
}