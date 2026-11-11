//last :(
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=500005;
int a[N];
int b[N];
int ans=0;
int cnt(int l,int r)
{
    int sum=0;
    for(int i=l;i<=r;i++)sum+=a[r]-a[i];
    return sum;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    a[0]=0;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++)
        for(int len=1;len+i<=n+1;len++)
           if(cnt(i,i+len-1)<=m)ans=max(ans,len);
    cout<<ans;
    return 0;
}
