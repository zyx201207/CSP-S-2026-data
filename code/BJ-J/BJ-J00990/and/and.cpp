#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long

const int N=1e5+10;
int n,m,a[N];

signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n<=20)
    {
        int maxn=0;
        for(int mask=1;mask<(1<<n);mask++)
        {
            int ans=(1<<35)-1;
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(mask&(1<<(i-1)))
                {
                    cnt++;
                    ans&=a[i];
                }
            }
            if(cnt==m) maxn=max(maxn,ans);
        }
        cout << maxn;
        return 0;
    }
    if(m==1)
    {
        int maxn=0;
        for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
        cout << maxn;
        return 0;
    }
    if(m==2)
    {
        int maxn=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                maxn=max(maxn,a[i]&a[j]);
        cout << maxn;
        return 0;
    }
    if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        cout << ans;
        return 0;
    }
    if(m==n-1)
    {
        int maxn=0;
        for(int i=1;i<=n;i++)
        {
            int ans=(1<<35)-1;
            for(int j=1;j<=n;j++)
            {
                if(j!=i) ans&=a[j];
            }
            maxn=max(maxn,ans);
        }
        cout << maxn << "\n";
        return 0;
    }
    bool flag=((1<<__lg(n))==n);
    for(int i=1;i<=n;i++) if(a[i]!=i-1) flag=0;
    if(flag)
    {
        cout << n-1;
        return 0;
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    cout << "\n";
    int ans=a[1];
    for(int i=2;i<=m;i++) ans=ans&a[i];
    cout << ans;
    return 0;
}
