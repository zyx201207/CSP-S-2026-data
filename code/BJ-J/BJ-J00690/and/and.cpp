#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],qzh[200005];
bool cmp(int x,int y)
{
    return x>y;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        qzh[i]=qzh[i-1]&a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1)
    {
        cout<<a[1];
        return 0;
    }
    if(m==n)
    {
        cout<<qzh[n];
        return 0;
    }
    if(m==2)
    {
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
        return 0;
    }
    cout<<a[m];
}