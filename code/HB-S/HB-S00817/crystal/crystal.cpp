#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int book[500005];
int b[500005];
int a[500005];
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
        book[a[i]]++;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
    {
        b[i]=a[i+1]-a[i];
    }
    int ren=1;
    int cnt=0;
    int k=1;
    for(int i=1;i<=n;i++)
    {
        if(m>=b[i]*ren)
        {
            if(a[i]!=a[i+1])
            {
                book[a[i+1]]+=ren;
                cnt=max(cnt,book[a[i+1]]);
            }
            m-=b[i]*ren;
            ren++;
        }
        else
        {
            while(m<b[i]*ren&&ren>1)
            {
                ren--;
                m+=a[k];
                k++;
            }
            if(m>=b[i]*ren)
            {
                if(a[i]!=a[i+1])
                {
                    book[a[i+1]]+=ren;
                    cnt=max(cnt,book[a[i+1]]);
                }
                m-=b[i]*ren;
                ren++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
