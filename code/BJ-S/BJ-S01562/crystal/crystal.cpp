#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+10;
int n;
ll a[MAXN],m;
ll now;
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int poi=1;
    for(int i=1;i<=n;i++){
        now+=(i-poi)*(a[i]-a[i-1]);
        while(now>m){
            now-=a[i]-a[poi];
            poi++;
        }
        ans=max(ans,i-poi+1);
    }
    cout<<ans<<'\n';
    return 0;
}
