#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N],b[N],p,t[M];
bool cz(int q)
{
    for(int i=1;i<=p;i++)
    {
        if(b[i]==q)
        {
            p=i-1;
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ks;
    for(int i=1;i<=n;i++)
    {
        p=0;
        ks=i-1;
        for(int j=1+ks;j<=n;j++)
        {
            if(cz(a[j]))
            {
                p++;
                b[p]=a[j];
            }
            else
            {
                p++;
                b[p]=a[j];
            }
        }
        for(int k=1;k<=p;k++)
        {
            t[b[k]]++;
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d ",t[i]);
    return 0;
}
