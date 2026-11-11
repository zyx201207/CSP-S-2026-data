#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=1;
    int cnt=1,vis;
    for(int i=1;i<=n;i++){
        cnt=1,vis=m;
        for(int j=i-1;j>=1;j--){
            if(vis>=a[i]-a[j]){
                cnt++;
                vis-=a[i]-a[j];
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
