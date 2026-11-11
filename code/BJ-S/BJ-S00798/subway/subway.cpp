#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int c,n,m,d,q,w[N],vis[N],k,A,T,x,y;
long long t[600][600];
struct node{
    long long i,q;
};
vector<node> sub[N];
vector<int> go[N];
queue<int> cha;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>A>>T;
            node xx;
            xx.i=i;
            xx.q=T;
            sub[A].push_back(xx);
            vis[A]++;
            if(A>1) cha.push(A);
        }
    }
    for(int i=1;i<=505;i++)
    {
        for(int j=1;j<=505;j++)
        {
            t[i][j]=1e15;
            if(i==j) t[i][j]=0;
        }
    }
    while(!cha.empty())
    {
        int now=cha.front();
        cha.pop();
        for(node i:sub[now])
        {
            for(node j:sub[now])
            {
                if(i.i==j.i) continue;
                t[i.i][j.i]=min(t[i.i][j.i],i.q+j.q);
                t[j.i][i.i]=t[i.i][j.i];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
            {
                t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
            }
        }
    }
    for(int k=1;k<=q;k++)
    {
        long long ans=1e15;
        cin>>x>>y;
        for(node i:sub[x])
        {
            for(node j:sub[y])
            {
                ans=min(ans,t[i.i][j.i]+w[x]+w[y]+i.q+j.q);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}