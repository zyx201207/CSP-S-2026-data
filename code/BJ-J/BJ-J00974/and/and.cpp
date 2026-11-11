#include<bits/stdc++.h>
using namespace std;

#define int long long
#define dnl "\n"

const int MAXN=2e5+5;
const int INF=0x3f3f3f3f3f3f3f3f;

int a[MAXN];

bool cmp(int x,int y)
{
    return x>y;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n;
    int m;
    cin>>n>>m;

    int mx=-INF;

    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        mx=0;

        for(int i=1;i<=n;i++)
        {
            mx&=a[i];
        }

        cout<<mx;
        return 0;
    }

    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                mx=max(mx,a[i]&a[j]);
            }
        }

        cout<<mx<<dnl;
        return 0;
    }

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a+1,a+n+1,cmp);

    cout<<a[m];

    return 0;
}
