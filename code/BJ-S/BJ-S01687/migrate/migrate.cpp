#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,x,y) for(i=x;i<=y;i++)
#define rF(i,x,y) for(i=x;i>=y;i--)
const int N=5e3+5;
int n,d,x[2000005],dis[N],cnt[N],ans,C,T;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    memset(dis,0x3f,sizeof dis);
    memset(cnt,0,sizeof cnt);
    int i;
    cnt[s]=1,dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(cnt[u]==2) 
        {
            // cout<<s<<' '<<u<<'\n';
            ans++;
        }
        F(i,u+1,n) 
        {
            if(x[i]-x[u]>d) break;
            if(dis[i]>dis[u]+1) dis[i]=dis[u]+1,q.push(i),cnt[i]=cnt[u];
            else if(dis[i]==dis[u]+1) cnt[i]+=cnt[u];
        }
    }
    return;
}
void solve()
{
    cin>>n>>d;
    int i;
    ans=0;
    F(i,1,n) cin>>x[i];
    if(C<=10)
    {
        F(i,1,n) bfs(i);
        cout<<ans<<'\n';
    }
    else if(C<=12)
    {
        int L=d/(x[2]-x[1]);
        if(L<=1) cout<<"0\n";
        else cout<<max(0ll,n-(2*L-1))<<'\n';
    }
    else
    {
        cout<<"0\n";
    }
    return;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0),cin.tie(0);
    T=1;
    cin>>C>>T;
    while(T--) {solve();}
}