#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",strout);
    int n,m,a[500005],b[500005],c[500005];
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int k = 1;k <= n;k++)
    {
        memset(b,0,sizeof(b));
        for(int i = k;i <= n;i++)
        {
            b[a[i]]++;
            bool flag = false;
            for(int j = 1;j <= i;j++)
            {
                if(a[j] == a[i])
                {
                    flag = true;
                    a[j] = a[i];
                    continue;
                }
                if(flag)
                {
                    a[j] = 0;
                    b[a[j]]--;
                }
            }
        }
        for(int i = 1;i <= m;i++)
        {
            if(b[i] > 0)
            {
                c[i]++;
            }
        }
    }
    for(int i = 1;i <= m;i++)
    {
        printf("%d ",c[i]);
    }
    return 0;
}
