#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
struct ss
{
    int a, t[25], id[25], js=1, w;
}s[N];
int c, n, m, d, q;
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    for(int i=1;i<=m;i++)
    {
        s[i].a=i;
    }
    scanf("%ld%ld%ld%ld%ld", &c, &n, &m, &d, &q);
    for(int i=1;i<=m;i++)
    {
        scanf("%ld", &s[i].w);
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%ld", &k);
        for(int j=1;j<=k;j++)
        {
            int x, y;
            scanf("%ld%ld", &x, &y);
            s[x][s[j].js].t=y;
            s[x][s[j].js].id=i;
            s[x].js++;
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x, y, ans=0, tot, oto;
        scanf("%ld%ld", &x, &y);
        bool f=false;
        if(s[x].js>1 || s[y].js>1)
        {
            if(s[x].js==1)
            {
                for(int j=1;j<=s[y].js;j++)
                {
                    if(s[x][1].id==s[y][i].id)
                    {
                        f=true;
                        tot=1;
                        oto=j;
                        break;
                    }
                }
            }
            else if(s[y].js==1)
            {
                for(int j=1;j<=s[x].js;j++)
                {
                    if(s[y][1].id==s[x][i].id)
                    {
                        f=true;
                        oto=1;
                        tot=j;
                        break;
                    }
                }
            }
            else
            {
                for(int j=1;j<=s[x].is;j++)
                {
                    for(int k=1;k<=s[y].js;k++)
                    {
                        if(s[y][j].id==s[x][k].id)
                        {
                            f=true;
                            tot=k;
                            oto=j;
                            break;
                        }
                    }
                    if(f==true)
                    {
                        break;
                    }
                }
            }
        }
        else if(s[x].js==1 && s[y].js==1)
        {
            if(s[y][1].id==s[x][1].id)
            {
                f=true;
                tot=1;
                oto=1;
            }
        }
        if(f==true)
        {
            ans+=s[x].w+s[x][tot].t+s[y][oto].t+s[y].w;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
