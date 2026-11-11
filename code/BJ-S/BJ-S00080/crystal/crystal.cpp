#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll sum=0;
    int t=1,cnt=0;
    int ans=0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum+=cnt*(a[i]-a[i-1]);
        cnt++;
        while(sum>m){
            sum-=(a[i]-a[t]);
            t++;
            cnt--;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
