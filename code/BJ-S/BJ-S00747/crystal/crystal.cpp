#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef __int128 i128;
typedef unsigned __int128 u128;
ll a[500005];
ll sum[500005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--)a[i]-=a[1];
    for(int i=n;i>=1;i--)sum[i]=sum[i+1]+a[i];

    ll maxx=0;
    for(int i=1;i<=n;i++){
        ll l=1,r=i,ans=0;
        while(l<=r){
            ll mid=l+r>>1;//mid-th index in sum
            if((i-mid)*a[i]-(sum[mid]-sum[i])<=m)
                ans=mid,r=mid-1;
            else l=mid+1;
        }
        maxx=max(maxx,i-ans+1);
    }
    cout<<maxx;
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
