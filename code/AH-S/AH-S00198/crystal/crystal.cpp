#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long l=1,r=0;
    while(r<=n){
        while(sum<=m&&r<=n){
            ans=max(ans,r-l+1);
            r++;
            sum+=(r-l)*(a[r]-a[r-1]);
        }
        l++;
        sum-=a[r]-a[l];
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
