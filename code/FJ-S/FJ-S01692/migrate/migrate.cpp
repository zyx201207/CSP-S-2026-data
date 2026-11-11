#include<bits/stdc++.h>
#define int long long
#define R read()
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define gc getchar
using namespace std;
int read()
{
    int x=0,f=1;
    char c=gc();
    while(c<'0'||c>'9') (c=='-'&&(f=-1,1)),c=gc();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=gc();
    return x*f;
}
void write(int x,char xx)
{
    static int st[35],tot=0;
    if(x<0) putchar('-'),x=-x;
    do{st[++tot]=x%10,x/=10;}
    while(x);
    while(tot) putchar(st[tot]+'0'),tot--;
    putchar(xx);
}
#define N 2000010
int cid;
int n,d,a[N],l[N],r[N],fa[N],ans,g[N];
pii f[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void meg(int x,int y){x=find(x),y=find(y),(x!=y&&(fa[x]=y,1));}
priority_queue<int,vector<int>,greater<int>>Q;
unordered_map<int,int>mp;
void solve()
{
    n=R,d=R,ans=0;
    for(int i=1;i<=n;i++) a[i]=R,fa[i]=i,l[i]=r[i]=0;
    if(n<=5000)
    {
        for(int i=1;i<=n;i++)
        {
            mp.clear(),f[i]={0,1},mp[0]=1;
            while(!Q.empty()) Q.pop();
            Q.push(0);
            for(int j=i+1,l=i;j<=n;j++)
            {
                while(a[j]-a[l]>d) mp[f[l].fi]-=f[l].se,l++;
                while(!Q.empty()&&mp[Q.top()]==0) Q.pop();
                if(Q.empty()) break;
                f[j]={Q.top()+1,mp[Q.top()]},mp[f[j].fi]+=f[j].se,Q.push(f[j].fi);
                if(f[j].se==2) ans++; 
            }
        }
    }
    else if(cid==11||cid==12)
    {
        mp.clear(),f[1]={0,1},mp[0]=1;
        while(!Q.empty()) Q.pop();
        Q.push(0),g[1]=0;
        for(int j=2,l=1;j<=n;j++)
        {
            while(a[j]-a[l]>d) mp[f[l].fi]-=f[l].se,l++;
            while(!Q.empty()&&mp[Q.top()]==0) Q.pop();
            if(Q.empty()) break;
            f[j]={Q.top()+1,mp[Q.top()]},mp[f[j].fi]+=f[j].se,Q.push(f[j].fi);
            if(f[j].se==2) ans++,g[j]=1;
            else g[j]=0;
        }
        int sum=ans;
        for(int i=2;i<=n;i++) sum-=g[n-i+2],ans+=sum;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            mp.clear(),f[i]={0,1},mp[0]=1;
            while(!Q.empty()) Q.pop();
            Q.push(0);
            for(int j=i+1,l=i;j<=n;j++)
            {
                while(a[j]-a[l]>d) mp[f[l].fi]-=f[l].se,l++;
                while(!Q.empty()&&mp[Q.top()]==0) Q.pop();
                if(Q.empty()) break;
                f[j]={Q.top()+1,mp[Q.top()]},mp[f[j].fi]+=f[j].se,Q.push(f[j].fi);
                if(f[j].se==2) ans++; 
            }
        }
    }
    write(ans,'\n');
}
int T=1;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cid=R,T=R;
    while(T--) solve();
    return 0;
}
/*
first get scc-like nodes
and legal (u,v) is like u->v->w,dis(u,v)=1,v and w in the same scc.or swap the relation.
maybe it's right
try to code it.
but I need to go to the toilet first.
saw ahtfd3101 and fzs7 on the way to the toilet,lol,3 qu brothers.
it's wrong.
waste 2.5h+ times.
17:45 48pts
*/