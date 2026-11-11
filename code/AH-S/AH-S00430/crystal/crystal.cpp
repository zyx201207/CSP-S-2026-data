#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010],s[500010];
bool check(int k)
{
    for(int i=k;i<=n;i++)
        if(k*a[i]-s[i]+s[i-k]<=m)return 1;

    return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int i;cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int l=1,r=n+1;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid))l=mid+1;else r=mid;
    }cout<<l-1;
}
