#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n,ans;
ll m,a[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    int l=1,r=1;
    ll tot=0;
    for(int r = 1;r<=n;r++){
        tot+=a[r];
        while((1LL*(r-l+1)*a[r]-tot)>m&&l<=r) tot-=a[l],l++;
        ans=max(ans,r-l+1);
    }
    cout << ans;
    return 0;
}