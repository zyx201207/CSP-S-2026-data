#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],s;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,greater<long long>());
    int l=1,r=0;
    while(r<n){
        if(a[l]-a[r+1]+s<=m)r++,ans=max(ans,r-l+1),s+=a[l]-a[r];
        else l++,s-=1ll*(r-l+1)*(a[l-1]-a[l]);
    }
    cout<<ans<<endl;
    return 0;
}
