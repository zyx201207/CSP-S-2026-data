#include<bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;
ll n,m;
ll a[N];
ll d[N];
ll sum[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)d[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++){
        sum[i]=sum[i-1]+d[i]*(i-1);
    }
    int ans=0;
    int r;
    for(r=1;r<=n;r++){
        if(sum[r]<=m){
            ans=max(ans,r);
            continue;
        }
        int l=1;
        while(sum[r]-sum[l]-(d[r]-d[l])*l>m&&l<=r)l++;
        if(l==r+1){ans=max(ans,1);continue;}
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}