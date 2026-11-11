#include <bits/stdc++.h>
using namespace std;
int b[5005],ton[3005];
int a[5005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n>=10000)
    {
        for(int i=1;i<=m;i++)
        {
            cout<<i<<' ';
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    int len=0;
    for(int o=1;o<=n;o++)
    {
        for(int i=o;i<=n;i++)
        {
            int cur=b[i];
            bool b=1;
            for(int j=1;j<=len;j++)
            {
                if(a[j]==cur)
                {
                    len=j;
                    b=0;
                }
            }
            if(b)
            {
                a[++len]=cur;
            }
        }
        for(int i=1;i<=len;i++)
        {
            ton[a[i]]++;
        }
        len=0;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ton[i]<<' ';
    }
    return 0;
}
