#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,now,j=1;
int a[500005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        now+=(a[i]-a[i-1])*(i-j);
        while(now>m){
            now-=(a[i]-a[j]);
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}
