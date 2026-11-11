#include <iostream>
#include <queue>
using namespace std;
const int MAXN=2e5;
int n,m,a[MAXN+10];
bool vis[MAXN+10];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1<<29;i;i>>=1)
    {
        queue<int>q;
        for(int j=1;j<=n;j++)
        {
            if((a[j]&i)&&!vis[j])
                q.push(j);
        }
        if(q.size()>=m)
        {
            int lst=0;
            while(!q.empty())
            {
                int now=q.front();
                for(int j=lst+1;j<now;j++)
                    vis[j]=true;
                lst=now;
                q.pop();
            }
            for(int j=lst+1;j<=n;j++)
                vis[j]=true;
        }
    }
    int ans=(1<<30)-1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            ans&=a[i];
    }
    cout<<ans<<endl;
}
