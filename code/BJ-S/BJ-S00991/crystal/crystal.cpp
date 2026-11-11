#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N];
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);int r=1,sum=m,ans=0;
    for(int l=1;l<=n;l++){
        while(r<n&&sum-(a[r+1]-a[r])*(r+1-l)>=0) sum-=a[r+1]-a[r]*(r+1-l),r++;
        ans=max(ans,r-l+1);
        if(r==l) r++;
        sum=a[l+1]-a[l]*(r-l+1);
    }
    cout<<ans;
    return 0;
}

