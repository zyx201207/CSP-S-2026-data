#include<bits/stdc++.h>
#define ll long long
#define F for
#define W while
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin),p1==p2)?EOF:*p1++)
static inline int read()
{
    int x=0,f=1;char ch=gc();
    W(!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}
    W(isdigit(ch)) x=x*10+(ch^48),ch=gc();
    return x*f;
}
const int MAXN=1000+5;
int c,n,m,d,q,cnt;
int w[MAXN],a[MAXN][MAXN],viszt[MAXN],visdt[MAXN];
vector<int> G[MAXN],b[MAXN];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    F(int i=1;i<=m;i++) w[i]=read();
    F(int i=1,k;i<=n;i++)
    {
        k=read();
        G[i].resize(k);
        F(int j=1,x;j<=k;j++)
        {
            x=read(),a[i][x]=read();
            b[x].push_back(i);
            G[i][j-1]=x;
        }
    }
    int st,ed;
    W(q--)
    {
        st=read(),ed=read();
        cnt++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({w[st],st});
        W(!pq.empty())
        {
            auto [d,u]=pq.top();pq.pop();
            if(u==ed)
            {
                cout<<d+w[ed]<<'\n';
                break;
            }
            if(viszt[u]==cnt) continue;
            viszt[u]=cnt;
            F(int i : b[u])
            {
                if(visdt[i]==cnt) continue;
                visdt[i]=cnt;
                F(int j : G[i])
                {
                    if(viszt[j]!=cnt) pq.push({d+a[i][u]+a[i][j],j});
                }
            }
        }
    }
    return 0;
}