#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[10005],k[505],a[505][10005];
long long t[10005][10005];
const long long num=1e17;
long long olivia(int x,int y)
{
    if(t[x][y]!=num) return t[x][y];
    for(int i=0;i<m;i++)
    {
        if(x==i||y==i) continue;
        if(t[i][y]!=num)
        {
            t[x][y]=olivia(x,i)+olivia(i,y);
            t[y][x]=t[x][y];
            return t[x][y];
        }
    }
    return 0;
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
        for(int j=0;j<k[i];j++)
        {
            int x;
            cin>>x;
            cin>>a[i][x];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i!=j)
            {
                t[i][j]=num;
                t[j][i]=num;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<505;j++)
        {
            if(a[j][i]!=0)
            for(int l=0;l<m;l++)
            {
                if(i!=l&&a[j][l]!=0)
                {
                    t[i][l]=min(t[i][l],(long long)a[j][i]+a[j][l]);
                    t[l][i]=t[i][l];
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;i++)
        {
            if(i!=j&&t[i][j]==num)
            {
                t[i][j]=olivia(i,j);
                t[j][i]=t[i][j];
            }
        }
    }
    for(int r=0;r<q;r++)
    {
        int x,y;
        cin>>x>>y;
        cout <<(t[x][y]+w[x]+w[y])<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
