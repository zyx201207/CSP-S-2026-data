#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],ans,sum[N];
bool check(int x){
    for(int i=1;i<=n-x+1;i++){
        int tmp=x*a[i+x-1]-(sum[i+x-1]-sum[i-1]);
        if(tmp<=m)return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
