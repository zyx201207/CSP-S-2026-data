#include<bits/stdc++.h>
using namespace std;
const int N=500005;
#define int long long
int n,m,sum,ans,a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1);
    for(int l=1,r=1;r<=n;r++){
        while(sum>m)  sum-=a[r]-a[l++];
        ans=max(ans,r-l+1);
        if(r==n)  continue;
        sum+=(a[r+1]-a[r])*(r-l+1);
    }
    cout<<ans<<"\n";
}