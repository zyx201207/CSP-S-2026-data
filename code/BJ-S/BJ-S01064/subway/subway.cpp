#include <bits/stdc++.h>
using namespace std;
const int M=5e5+5;
const int N=505;
int c,n,m,d,q,w[M],k[N],v[N][M],t[N][M],f[M],x,y;
vector<int> a[M];
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    memset(f,0x3f,sizeof(f));
    f[x]=0;
    while(!q.empty())
    {
        int t1=q.front();
        q.pop();
        for (int i=0;i<a[t1].size();i++)
        {
            int nt=a[t1][i];
            int tmp;
            for (int j=1;j<=k[nt];j++)
                if (t1==v[nt][j])
                {
                    tmp=j;
                    break;
                }
            for (int j=1;j<=k[nt];j++)
                if (f[v[nt][j]]>f[t1]+t[nt][tmp]+t[nt][j])
                {
                    f[v[nt][j]]=f[t1]+t[nt][tmp]+t[nt][j];
                    q.push(v[nt][j]);
                }
        }
    }
    return ;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for (int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&k[i]);
        for (int j=1;j<=k[i];j++)
        {
            scanf("%d %d",&v[i][j],&t[i][j]);
            a[v[i][j]].push_back(i);
        }
    }
    while(q--)
    {
        scanf("%d %d",&x,&y);
        bfs(x);
        printf("%d\n",f[y]+w[x]+w[y]);
    }
    printf("\n");
    return 0;
}