#include <iostream>
#include <queue>
using namespace std;
queue <int> q,p;
int vis[100005],dis[10005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    /*for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(!vis[a])
        {
            q.push(a);
            vis[a]=1;
        }
        else{
            while(q.front()!=a)
            {
                q.pop();
            }
        }
    }
    while(p.size()-1)
    {
        for(int i=1;i<=q.size();i++)
        {
            dis[q.front()]++;
            p.push(q.front());
            q.pop();
            vis[q.front()]=0;
        }
        while(p.size())
        {
            int x=p.front();
            if(!vis[x])
            {
                q.push(x);
                vis[x]=1;
            }
            else
            {
                while(q.front()!=x)
                {
                    q.pop();
                }
            }

        }
        for(int i=1;i<=q.size();i++)
        {
            dis[q.front()]++;
            p.push(q.front());
            q.pop();
            vis[q.front()]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {

        cout<<dis[i]<<" ";
    }*/
    cout<<n<<" "<<m<<" "<<m;
    return 0;
}
