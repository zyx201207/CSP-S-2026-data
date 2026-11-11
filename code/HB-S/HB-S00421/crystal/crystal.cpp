#include<bits/stdc++.h>
#define it long long
using namespace std;
it n,m,a[500005],l=1,sum,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(it i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(it i=1;i<=n;i++){
        sum+=(i-l)*(a[i]-a[i-1]);
        while(sum>m) sum-=a[i]-a[l],l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
