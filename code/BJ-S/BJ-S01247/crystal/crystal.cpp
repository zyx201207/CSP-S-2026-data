#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int n;
ll m;
ll a[N],s[N];
int dp[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i-1;
        int sum=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[i]*(i-1-mid+1)-(s[i-1]-s[mid-1])<=m) sum=mid,r=mid-1;
            else l=mid+1;
        }
        dp[i]=i-sum+1;
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}