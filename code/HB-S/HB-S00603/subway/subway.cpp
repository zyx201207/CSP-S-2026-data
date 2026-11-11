#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,id;
};
vector <node> v[10005];
vector <int> u[100005];
int a[100005];
bool b[100005];
int bo[500005][20];
int ans=1e9;
void dfs(int x,int id,int e,int cur)
{
    if(x==e)
    {
        ans=min(ans,cur+bo[e][id]);
        return ;
    }
    if(b[x])
    {
        return ;
    }
    b[x]=1;
    //cout<<endl<<cur<<"   ";
    if(cur>=ans)
    {
        return ;
    }
    for(node i:v[x])
    {
        //cout<<x<<" ---"<<i.x<<" ";
        if(i.id!=id)
        {
            //cout<<bo[x][id]<<" "<<bo[x][i.id]<<endl;
            dfs(i.x,i.id,e,cur+bo[x][id]+bo[x][i.id]);
        }
        else
        {
            dfs(i.x,i.id,e,cur);
        }
    }
    b[x]=0;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int last=0;
        for(int j=1;j<=k;j++)
        {
            int x,t;
            cin>>x>>t;
            u[x].push_back(i);
            bo[x][i]=t;
            if(last!=0)
            {
                //cout<<last<<" "<<x<<endl;
                v[last].push_back({x,i});
                v[x].push_back({last,i});

            }
            last=x;
        }
    }
    for(int i=1;i<=q;i++)
    {
        int s,e;
        cin>>s>>e;
        ans=1e9;
        memset(b,0,sizeof(b));
        for(int j:u[s])
        {
            //cout<<1;
            dfs(s,j,e,bo[s][j]);
        }
        cout<<ans+a[s]+a[e]<<endl;
    }
    return 0;
}
