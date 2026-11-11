#include <bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
int n,m,a[N],s[N],ans;
int calc(int l,int r)
{
    return s[l]-s[r+1]+(r-l+1)*(s[r+1]-s[r]);
}
int get(int x)
{
    int l=1,r=x;
    while(l<r)
    {
        int mid=(l+r)>>1;
//        cout<<calc(mid,x)<<"\n";
        if(calc(mid,x)>m)l=mid+1;
        else r=mid;
    }
    return l;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=n-1;i>=1;i--)
    {
        a[i]=a[n]-a[i];
        s[i]=s[i+1]+a[i];
    }
//    for(int i=1;i<=n;i++)cout<<s[i]<<" ";
//    cout<<calc(3,5)<<endl;
    for(int i=n;i>=1;i--)
    {
        ans=max(ans,i-get(i)+1);
//        cout<<get(i)<<" ";
    }cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9
*/
