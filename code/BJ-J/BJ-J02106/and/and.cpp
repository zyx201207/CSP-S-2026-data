#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
int a[N];
int cnt[4];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int maxn=-1;
    for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
    if(m==1)cout<<maxn;
    else if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==2)
    {
        int ans=a[1]&a[2];
        for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)ans=max(a[i]&a[j],ans);
        cout<<ans;
    }
    else if(maxn<4)
    {
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)cnt[a[i]]++;
        if(cnt[3]>=m)cout<<3;
        else if(cnt[3]+cnt[2]>=m)cout<<2;
        else if(cnt[3]+cnt[1]>=m)cout<<1;
        else cout<<0;
    }
    else
    {
        sort(a+1,a+n+1);
        int ans=a[n];
        for(int i=n;i>=0;i--)
        {
            if(m==0)break;
            m--;
            ans&=a[i];
        }
        cout<<ans;
    }
    return 0;
}
