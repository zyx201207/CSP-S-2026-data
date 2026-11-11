#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;++i)   scanf("%d",&a[i]);
    for(int i=1;i<=m;++i)
    {
        if(i==1)    cout << 1 <<"\n";
        else
        {
            int minn=n+1;
            for(int j=1;j<=n/2;++j)
            {
                for(int p=n-j+1;p>=n-minn;--p)
                {
                    if(a[j]==a[p])
                        minn=min(minn,n-p);
                        break;
                }
            }
            cout << minn << " ";
        }
    }
    return 0;
}
