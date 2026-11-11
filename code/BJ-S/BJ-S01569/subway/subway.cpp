#include<iostream>
#include<vector>
using namespace std;
const int maxn=501;
const int maxm=500001;
struct Station{int id,to;};
vector<Station> subway;
vector<Station> e[maxm];//每个站点能到的一条线上的站点，v=stage to stage
int ID,n,m,max_ntom,k,w[maxm],l,r;
long long ans=0;
void dfs(int x,long long res)
{
    if(x==r)
    {
        res+=w[r];
        ans=max(ans,res);
        return;
    }
    for(Station t:e[x])
    {
        res+=t.to;
        dfs(t.id,res);
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>ID>>n>>m>>max_ntom>>k;
    for(int i=1;i<=m;i++)cin>>w[i];
    if(ID>=7 && ID<=11)
    {
        for(int i=1;i<=n;i++)
        {
            int t,a,b,c,d;
            cin>>t>>a>>b>>c>>d;
            Station x,y;
            x.id=a;
            y.id=c;
            y.to=b+d;
            x.to=y.to;
            e[a].push_back(y);
            e[c].push_back(x);
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            int t;
            cin>>t;
            subway.resize(t+1);
            for(int j=1;j<=t;j++)
            {
                int id,to;
                cin>>id>>to;
                subway[j].id=id;
                subway[j].to=to;
            }
            for(int u=1;u<=t-1;u++)
            {
                for(int v=1;v<=t;v++)
                {
                    if(u!=v)
                    {
                        Station x,y;
                        x.id=subway[v].id;
                        y.id=subway[u].id;
                        x.to=subway[u].to+subway[v].to;
                        y.to=x.to;
                        e[y.id].push_back(x);
                        e[x.id].push_back(y);
                    }
                }
            }
        }
    }
    
    while(k--)
    {
        cin>>l>>r;
        ans=0;
        long long res=w[l];
        dfs(l,res);
        cout<<ans<<"\n";
    }
    return 0;
}