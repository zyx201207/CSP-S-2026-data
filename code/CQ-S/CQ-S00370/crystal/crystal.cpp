#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
//你会得到你想要的结果的
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    long long l=1,r=1,used=0,ans=0;
    while(l<=n){
        while(used<=m&&r<n){
            used+=(r-l+1)*(a[r+1]-a[r]);
            r++;
        }
        used-=(r-l)*(a[r]-a[r-1]);
        r--;
        ans=max(ans,r-l+1);
        l++;
        used-=(a[r]-a[l-1]);
    }
    cout<<ans;
    return 0;
}
//拉普兰德天下第一