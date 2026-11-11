#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],x[500005];
bool f1=1,f2=1;

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1&&a[i]!=a[i-1])
            f1=0;
    }
    for(int i=1;i<=n;i++)
    {
        x[i]=a[i]-a[i-1];
        if(i>2&&x[i]!=x[i-1])
            f2=0;
    }
    sort(a+1,a+n+1);
    if(f1)
    {
        cout<<n;
        return 0;
    }
    if(f2)
        for(int i=1;i<=n;i++)
            if(m<x[2]*i*(i+1)/2)
            {
                cout<<i;
                return 0;
            }
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        int tmp=m,cnt=1;
        for(int j=i-1;j>0;j--)
        {
            if(tmp==0)
                break;
            if(a[i]-a[j]<=tmp)
            {
                cnt++;
                tmp-=a[i]-a[j];
            }
        }
        maxn=max(cnt,maxn);
    }
    cout<<maxn;
    return 0;
}
