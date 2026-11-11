#include <bits/stdc++.h>
using namespace std;
int num[5005][5005];
int book[5005][5005];
int w[5005];
int s,t,ans;
int minn=217483640;
int c,n,m,d,q;
void dfs(int p)
{
    if(p==t)
    {
        minn=min(ans,minn);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(num[p][i]!=0&&book[p][i]==0)
        {
            ans+=num[p][i];
            book[p][i]=1;
            book[i][p]=1;
            dfs(i);
            ans-=num[p][i];
            book[p][i]=0;
            book[i][p]=0;
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    if(c==7||c==8||c==9||c==10||c==11||c==0)
    {
        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            int a,b,z,x;
            cin>>a>>b>>z>>x;
            num[a][z]=b+x;
            num[z][a]=b+x;
        }
        while(q--)
        {
            cin>>s>>t;
            ans=0;
            memset(book,0,sizeof(book));
            dfs(s);
            cout<<minn+w[s]+w[t]<<'\n';
        }
    }

    return 0;
}
