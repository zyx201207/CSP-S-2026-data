#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],s[N];
signed main()
{
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
        s[i]=s[i-1]+a[i];
    int l=1,r=n,mid,ans=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        bool flag=0;
        for(int i=1;i+mid-1<=n;i++)
        {
            if(a[i+mid-1]*mid-(s[i+mid-1]-s[i-1])<=m)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            l=mid+1;
            ans=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
}