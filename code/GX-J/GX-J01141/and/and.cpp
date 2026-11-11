#include <bits/stdc++.h>
using namespace std;
long long a[2000005],sum;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn=-1000000;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]>maxn) maxn=a[i];
        }
        cout << maxn;
        return 0;
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if((a[i]&a[j])>maxn)
                {
                    maxn=a[i]&a[j];
                }
            }
        }
        cout << maxn;
        return 0;
    }
    sum = a[1];
    if(m==n)
    {
        for(int i=2;i<=n;i++)
        {
            sum=(a[i]&sum);
        }
        cout << sum;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=m;i++)
    {
        sum =(a[i]&sum);
    }
    cout << sum;
    return 0;
}
