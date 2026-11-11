#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
int book[2000001];
long long x[2000001];
bool flag=false;
int minn;
int gs;
int q,z;
void dfs(int xz,int c)
{
    if(xz==z)
    {
        if(c==minn)
        {
            if(flag==true)flag=false;
            else flag=true;
        }
        else if(c<minn)
        {
            flag=false;
            minn=c;
        }
        return;
    }
    book[xz]=c;
    for(int i = xz;x[i]-x[xz]<=d&&i<=z;i++)
    {
        if(book[i]<c+1)continue;
        dfs(i,c+1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int k = 1;k<=t;k++)
    {
        scanf("%d%d",&n,&d);
        gs=0;
        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&x[i]);
        }
        if(x[n]-x[1]<=d)
        {
            printf("0\n");
            continue;
        }
        for( q = 1;q<=n;q++)
        {
            for( z = q+1;z<=n;z++)
            {
                if(x[z]-x[q]<=d)continue;
                memset(book,0x3f3f3f,sizeof book);
                minn=2147483647;
                flag=false;
                dfs(q,1);
                if(flag)
                {
                    gs++;
                }
            }
        }
        printf("%d\n",gs);
    }
    return 0;
}
