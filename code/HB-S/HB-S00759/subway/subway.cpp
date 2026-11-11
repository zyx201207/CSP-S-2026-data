#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qu;
int w[500005];
vector<int>a[500505];
int t[505][500505],book[500505];
void asdf(int x)
{
    queue<pair<int,int> > q;
    q.push({0,x});
    for(int i=1;i<=n+m;i++)
    {
        book[i]=0;
    }
    book[x]=1;
    while(!q.empty())
    {
        int s=q.front().second;
        q.pop();
        if(book[s]==2) continue;
        book[s]=2;
        for(int i=0;i<a[s].size();i+=2)
        {
            int e=a[s][i],v=a[s][i+1];
            if(book[e]!=2)
            {
                if(t[x-m][e]==0||t[x-m][s]+v<t[x-m][e])
                {
                    t[x-m][e]=t[x-m][s]+v;
                    q.push({-t[x-m][e],e});
                    //cout << x << ' ' << s << ' ' << e << ' ' << t[x-m][e] << '\n';
                }
                else if(book[e]==0)
                {
                    q.push({-t[x-m][e],e});
                    //cout << x << ' ' << s << ' ' << e << ' ' << t[x-m][e] << '\n';
                }
            }
        }
    }
    return ;
}
void asdf1(int x)
{
    priority_queue<pair<int,int> > q;
    q.push({0,x});
    for(int i=1;i<=n+m;i++)
    {
        book[i]=0;
    }
    book[x]=1;
    while(!q.empty())
    {
        int s=q.top().second;
        q.pop();
        if(book[s]==2) continue;
        book[s]=2;
        for(int i=0;i<a[s].size();i+=2)
        {
            int e=a[s][i],v=a[s][i+1];
            if(book[e]!=2)
            {
                if(t[x-m][e]==0||t[x-m][s]+v<t[x-m][e])
                {
                    t[x-m][e]=t[x-m][s]+v;
                    q.push({-t[x-m][e],e});
                    //cout << x << ' ' << s << ' ' << e << ' ' << t[x-m][e] << '\n';
                }
                else if(book[e]==0)
                {
                    q.push({-t[x-m][e],e});
                    //cout << x << ' ' << s << ' ' << e << ' ' << t[x-m][e] << '\n';
                }
            }
        }
    }
    return ;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> qu;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=1;j<=x;j++)
        {
            int y,z;
            scanf("%d%d",&y,&z);
            a[y].push_back(m+i);
            a[y].push_back(z);
            a[m+i].push_back(y);
            a[m+i].push_back(z);
            t[i][y]=z;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(c<=11)
            asdf1(m+i);
        else
            asdf(m+i);
    }
    for(int i=1;i<=qu;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int ans=1e9;
        for(int j=1;j<=n;j++)
        {
            ans=min(ans,t[j][x]+t[j][y]);
        }
        printf("%d\n",ans+w[x]+w[y]);
    }
    return 0;
}
