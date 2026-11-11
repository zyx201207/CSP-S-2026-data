#include<bits/stdc++.h>
using namespace std;
int a[500005],p[500005],cnt[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int point=0;
        memset(p,0,sizeof(p));
        for(int j=i;j<=n;j++)
        {
            int x=a[j],f=1;
            for(int h=1;h<=point;h++)
            {
                if(p[h]==x)
                {
                    p[h]=x;
                    point=h;f=0;
                    break;
                }
            }
            if(f==1){point++;p[point]=x;}
        }
        for(int j=1;j<=point;j++)cnt[p[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
