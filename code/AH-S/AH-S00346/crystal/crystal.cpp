#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans;
int a[N],sum[N];
bool check(int r,int len){
    int l=r-len+1;
    return sum[r]-sum[l]-(a[r]-a[l])*(l-1)<=m;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,mx=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(i,mid)){
                mx=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        ans=max(ans,mx);
    }
    cout<<ans;
    return 0;
}

