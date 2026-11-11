#include<bits/stdc++.h>
using namespace std;
int n,k;
struct edge
{
    int head,v,nxt;
}e[2000005];
int cnt;
void add(int u,int v)
{
    e[++cnt].v=v;
    e[cnt].nxt=e[u].head;
    e[u].head=cnt;
}
int rt,len[1000005],len2[1000005],dep[1000005];
void dfs0(int x,int fa)
{
    len[x]=len2[x]=0;
    for(int i=e[x].head;i;i=e[i].nxt)
    {
        if(e[i].v==fa) continue;
        dep[e[i].v]=dep[x]+1;
        dfs0(e[i].v,x);
        if(len[e[i].v]+1>len[x])
        {
            len2[x]=len[x];
            len[x]=len[e[i].v]+1;
            if(len2[e[i].v]+1>len2[x])
                len2[x]=len[e[i].v]+1;
        }
        else if(len[e[i].v]+1>len2[x])
            len2[x]=len[e[i].v]+1;
    }
}
void dfsf(int x,int pre,int fa)
{
    rt=x;
    int maxx=-1,maxx2=-1;
    for(int i=e[x].head;i;i=e[i].nxt)
    {
        if(e[i].v==fa) continue;
        if(len[e[i].v]>maxx)
        {
            maxx2=maxx;
            maxx=len[e[i].v];
        }
        else if(len[e[i].v]>maxx2) maxx2=len[e[i].v];
    }
    pre=max(pre+1,maxx2+2);
    if(pre>maxx) return;
    for(int i=e[x].head;i;i=e[i].nxt)
    {
        if(e[i].v==fa) continue;
        if(len[e[i].v]==maxx)
        {
            dfsf(e[i].v,pre,x);
            break;
        }
    }
}
int maxx;
int tot[1000005],dp[1000005][2];
deque<pair<int,int> >st;
void dfs(int x,int l,int fa)
{
    if(len[x]==l)
    {
        dp[x][0]=dp[x][1]=tot[x]=1;
        if(fa>=1) st.push_front({fa,len2[x]+1});
        return;
    }
    int deg=0;
    for(int i=e[x].head;i;i=e[i].nxt)
    {
        if(e[i].v==fa) continue;
        if(len[e[i].v]<l) continue;
        while(!st.empty()) st.pop_back();
        dfs(e[i].v,l,x);
        tot[x]+=tot[e[i].v];
        dp[x][1]+=dp[e[i].v][1];
        deg++;
    }
    dp[x][1]++;
    if(deg>=2)
    {
        dp[x][0]=dp[x][1];
        while(!st.empty()) st.pop_back();
    }
    else
    {
        while(!st.empty()&&dep[st.back().first]-dep[x]+st.back().second>l) st.pop_back();
        if(st.empty()) dp[x][0]=dp[x][1];
        else dp[x][0]=dp[st.back().first][1];
    }
    int tmp=fa;
    while(!st.empty()&&dep[st.front().first]-dep[x]+st.front().second<len2[x])
    {
        tmp=st.front().first;
        st.pop_front();
    }
    if(tmp>=1) st.push_front({tmp,len2[x]-(dep[tmp]-dep[x])+1});
    maxx=max(maxx,dp[x][1]-dp[x][0]);
    tot[x]++;
}
bool solve(int x)
{
    maxx=0;
    for(int i=1;i<=n;i++)
        tot[i]=0;
    while(!st.empty()) st.pop_back();
    dfs(rt,x,-1);
    return tot[rt]-maxx<=k;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            add(u,v),add(v,u);
        }
        rt=1;
        dep[1]=0;
        dfs0(1,-1);
        dfsf(1,0,-1);
        dep[rt]=0;
        dfs0(rt,-1);
        int l=0,r=n;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(solve(mid)) r=mid;
            else l=mid+1;
        }
        cout<<l<<"\n";
        cnt=0;
        for(int i=1;i<=n;i++)
            e[i].head=0;
    }
    return 0;
}
