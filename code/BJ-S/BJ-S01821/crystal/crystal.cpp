#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=5e5+10;
int a[N],sum[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int j=1,ans=0;
    for(int i=1;i<=n;i++)
    {
        while(a[i]*(i-j+1)-(sum[i]-sum[j-1])>m)j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans<<endl;
    return 0;
}
/*
5 5
1 2 4 8 9
3

5 8
-3 -1 2 2 7
*/