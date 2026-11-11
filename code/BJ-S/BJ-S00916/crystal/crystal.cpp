#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans,sum;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1;
    for(int i=1;i<=n;i++){
        if(i==1){
            ans=1;
            l=1;
            continue;
        }
        sum+=(i-l)*(a[i]-a[i-1]);
        while(sum>m){
            sum-=a[i]-a[l];
            l++;
        }
        if(sum<=m) ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
