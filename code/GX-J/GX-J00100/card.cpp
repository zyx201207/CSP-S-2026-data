#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,b[500005],a[500005],ton[500005],ton2[500005];
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>b[i];//1213
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = i;j<=n;j++)
        {
            int temp;
            if(j!=temp)
            {
                a[j] = b[temp];
            }
            else
            {
                a[j] = b[j];
            }
            ton[a[j]]++;
            if(ton[a[j]]>1)
            {
                for(int c = 1;c<=j;c++)
                {
                    if(a[c] == a[j])
                    {
                        temp = j;
                        j = c;
                    }
                }
            }
        }
        for(int j = 1;j<=n;j++)
        {
            if(a[j] == j)
            {
                ton2[j]++;
            }
        }
    }
    for(int i = 1;i<=n;i++)
    {
        cout<<ton2[i];
    }
    return 0;
}
