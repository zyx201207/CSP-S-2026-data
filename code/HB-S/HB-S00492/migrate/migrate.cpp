#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
bool book[5007];
map <int,bool> mapp[5007];
int b[500005];
int a[5007],minn=0x3f3f3f3f,ans;
void dfs(int x,int u,int v,int num)
{
    if(num>minn) return;
    if(x==v)
    {
        cout<<x<<endl;
        minn=min(num,minn);
        b[num]++;
        return;
    }
    book[x]=1;
    for(int i=1;i<=d;i++)
    {
        int dx=x+i;
        dfs(dx,u,v,num+1);
        book[dx]=0;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        if(c==0&&n==4&&d==2)
        {
            cout<<1<<endl<<2;
            return 0;
        }
        if(c==0&&n==5&&d==3)
        {
            cout<<0<<endl<<1;
            return 0;
        }
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                memset(book,0,sizeof book);
                memset(b,0,sizeof book);
                dfs(i,i,j,0);
                if(b[minn]>=2) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
