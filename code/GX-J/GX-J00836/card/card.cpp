#include <bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
int a[N];
int ret[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int now=i;
        int p=i;
        while(now<=n)
        {
            for(int j=now+1;j<=n;j++)
            {
                if(a[j]==a[now])
                {
                    p=j;
                }
            }
            ret[a[now]]++;
            now=p+1;
            p=now;
        }

    }
    for(int i=1;i<=m;i++)
    {
        cout<<ret[i]<<" ";
    }
    return 0;
}
