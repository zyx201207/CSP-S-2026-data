#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q;
int X,Y;
int t;
int kt[1005];
int a[1005][1005];//xian    ditiezhan  == (t ting-->tai )///////////////////////////
int p,o;
int x[1005][1005];//a xian-->b xian  huan cheng dai jia
int s[1005][1005];
int h[1005];
int g;
int dis[1005][1005];
int u[1005];
int v[1005];
int w[1005];
int top;
int main()
{

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>kt[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        for(int j=1;j<=t;j++)
        {
            cin>>p>>o;//ditiezhan  ting-->tai
            a[i][p]=o;
        }
    }
    for(int i=1;i<=m;i++)//NO.i   di tie zhan
    {
            for(int j=1;j<=n;j++)//xian
            {
                for(int z=j+1;z<=n;z++)//xian
                {
                    if(a[j][i]!=0 && a[z][i]!=0)
                    {
                        g=a[j][i]+a[z][i];
                    s[j][z]=g;
                    s[z][j]=g;
                    }
                }
            }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            top++;
            u[top]=i;
            v[top]=j;
            if(s[i][j]!=0)
            {
                dis[i][j]=s[i][j];
            }
            else
            {
                dis[i][j]=100000000;
            }
        }
    }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=top;j++)
            {
                if(dis[i][v[j]]<dis[i][u[j]]+w[j])
                {
                    dis[i][v[j]]=dis[i][u[j]]+w[j];
                }
            }
        }
    for(int i=1;i<=q;i++)
    {
        cin>>X>>Y;
        cout<<dis[X][Y]+kt[X]+kt[Y]<<endl;
    }
    return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 2 3 0 2
1 2 3
2 1 1 2 1
2 2 1 3 1
1 2
1 3
*/
