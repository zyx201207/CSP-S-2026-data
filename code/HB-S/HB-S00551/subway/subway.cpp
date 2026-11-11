#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
struct
{
    int k;
    int a[5005],t[5005];
}sub[5005];
int x,y;
int sta[505][25];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>sub[i].k;
        for(int j=1;j<=sub[i].k;j++)
        {
            cin>>sub[i].a[j]>>sub[i].t[j];
            sta[sub[i].a[j]][i]++;
        }
    }
    while(q--)
    {
        cin>>x>>y;
        int ans=0;
        ans+=(w[x]+w[y]);
        for(int i=x;i<=y;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(sta[i][j]==1)
                {
                    for(int p=1;p<=sub[j].k;p++)
                    {
                        if(sub[j].a[p]==i)
                            ans+=sub[j].t[i];
                    }
                }
            }
        }
        cout<<ans-4<<endl;
    }
    return 0;
}