#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+8;
int a[MAXN];
int f[MAXN];
int n;
int z[5008][5008];
long long d;
void bfs(int s)
{
    int cnt=0;
    queue<int>q;
    q.push(s);
    f[s]=0;
    while(!q.empty())
    {
        auto u=q.front();
        q.pop();
        int b=0;
        while(a[u]+d>=a[u+(++b)] && u+b<=n)
        {
            if(f[u+b]==f[u]+1)z[s][u+b]++;
            if(f[u+b]>f[u]+1)f[u+b]=f[u]+1,q.push(u+b);
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t,c;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                z[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            memset(f,0x3f,sizeof(f));
            bfs(i);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cnt+=(z[i][j]==2);
            }
        }
        cout<<cnt<<"\n";
    }
}
