#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n;
long long m;
long long a[N];
long long sum[N];
long long calc(int l,int r,long long val)
{
    int len=r-l+1;
    return val*len-(sum[r]-sum[l-1]);
}
int check(int i)
{
    int l=1,r=i;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(calc(mid,i,a[i])<=m) ans=mid,r=mid-1;
        else    l=mid+1;
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int d=check(i);
        ans=max(ans,i-d+1);
    }
    cout<<ans;
    return 0;
}