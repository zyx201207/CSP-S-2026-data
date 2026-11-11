#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int a[200001];
int f[200001][2];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==m)
    {
        int sum;
        cin>>sum;
        for(int i=2;i<=n;i++)
        {
            cin>>a[i];
            sum&=a[i];
        }
    }
    else if(m==1)
    {
        int maxn=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            maxn=max(maxn,a[i]);
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            f[i][1]=a[i];
        }
        int maxn=0;
        for(int k=2;k<=m;k++)
        {
            for(int i=1;i<=n;i++)
            {
                f[i][k%2]=0;
                for(int j=1;j<=n;j++)
                {
                    if(j==i)
                        continue;
                    f[i][k%2]=max(f[i][k%2],a[i]&f[j][(k-1)%2]);
                }
                if(k==m)
                    maxn=max(maxn,f[i][k%2]);
            }
        }
        cout<<maxn;
    }
    return 0;
}
