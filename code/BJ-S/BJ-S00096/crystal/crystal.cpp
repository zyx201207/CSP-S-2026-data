#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans=-1e9;
int check(int x)
{
    int s=m,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=x)
        {
            s-=(x-a[i]);
            cnt++;
            if(s<0) return cnt;
        }
    }
    return cnt;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int l=a[1],r=a[n],i=0;
    while(l<r&&i<=n)
    {
        int mid=a[++i];
        if(check(mid)<ans)
        {
            l=a[++i];
        }
        else
        {
            ans=check(mid);
        }
    }
    cout<<ans;
    return 0;
}
