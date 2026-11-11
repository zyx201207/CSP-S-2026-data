#include <bits/stdc++.h>

using namespace std;
int a[500010],b[500010],t[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    int cntb=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=cntb;k++)
            {
                if(b[k]==a[j])
                {
                    for(int s=k;s<=cntb;s++)
                    {
                        b[s]=0;
                    }
                }
            }
            b[++cntb]=a[j];
        }
        for(int j=1;j<=cntb;j++)
        {
            if(b[j]>0)
            {
                t[b[j]]++;
            }
            b[j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout <<t[i]<<" ";
    }
    return 0;
}
