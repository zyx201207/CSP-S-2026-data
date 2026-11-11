#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;
int n,ans;
ll m,a[500005],c;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=1;
    while(r<n){
        r++;
        c+=(r-l)*(a[r]-a[r-1]);
        while(c>m){
            c-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
        // cout<<l<<" "<<r<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}