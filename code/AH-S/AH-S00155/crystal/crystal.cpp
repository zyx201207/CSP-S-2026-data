#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],ans=1;
int cha;
int f(int pos)
{
    int num=m;
    int cnt=1;
    for(int i=pos;i>=1;i--)
    {
        num-=a[pos+1]-a[i];
        if(num<0)break;
        cnt++;
    }
    return cnt;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    bool flag=1;
    if(n<=2)
    {
        if(n==1)cout<<1;
        else
        {
            if(a[2]-a[1]<=m)cout<<2;
            else cout<<1;
        }
        return 0;
    }
    else
    {
        cha=a[2]-a[1];
        for(int i=3;i<=n;i++)
        {
            if(a[i]-a[i-1]!=cha){flag=0;break;}
        }
    }
    if(flag)
    {
        int cnt1=1;
        for(int i=1;i<n;i++)
        {
            m-=i*cha;
            if(m<0)break;
            cnt1++;
        }
        cout<<cnt1;return 0;
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,f(i-1));
    }
    cout<<ans;
    return 0;
}
