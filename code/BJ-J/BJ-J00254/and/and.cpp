#include <bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(int c,int d)
{
    return c>d;
}
bool b[200005][31];
int ans=0;
void f(int x)
{
    int k=a[x],num=0;
    while (k)
    {
        b[x][++num]=k%2;
        k/=2;
    }
    ans=max(ans,num);
    return;
}
long long c[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        f(i);
    }
    for (int i=ans;i>=1;i--)
    {
        int sum=0;
        for (int j=1;j<=n;j++)
        {
            sum+=b[j][i];
        }
        if (sum<m)
        {
            for (int j=1;j<=n;j++)
            {
                b[j][i]=0;
            }
        }
        else
        {
            break;
        }
    }
    for (int i=1;i<=n;i++)
    {
        long long z=1;
        for (int j=1;j<=ans;j++)
        {
            c[i]+=z*(long long)(b[i][j]);
            z*=2;
        }
    }
    sort(c+1,c+n+1,cmp);
    long long cnt=c[1];
    for (int i=2;i<=m;i++)
    {
        cnt=cnt&c[i];
    }
    cout << cnt;
    return 0;
}
