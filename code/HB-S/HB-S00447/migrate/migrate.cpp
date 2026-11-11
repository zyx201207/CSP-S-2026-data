#include<bits/stdc++.h>
using namespace std;

const int N=500,M=1e5+10;
int h[N],e[M],ne[M],idx;
int n,d;
int ans;
queue<int>q;
bool st[N];
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void bfs(int u,int v)
{
    int cnt=0;
    memset(st,0,sizeof st);
    q.push(u);
    st[u]=1;

    while(q.size())
    {
        int t=q.front();
        q.pop();
        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(j==v) cnt++;
            else{
                if(!st[j])
                {
                    q.push(j);
                    st[j]=1;
                }

            }
        }
    }
    if(cnt==2) ans++;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T,c;
    cin>>c>>T;
    while(T--)
    {
        int a[N];
        cin>>n>>d;
        memset(a,0,sizeof a);
        memset(h,-1,sizeof h);
        for(int i=1;i<=n;i++) cin>>a[i];

        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(a[j]-a[i]<d) add(j,i),add(i,j);
                else break;
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(i==j)continue;
                bfs(i,j);
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
