#include<iostream>
#include<stack>
using namespace std;
int n,m;
int a[500005];
int f[500005],s[500005],ggp[300005];
int sf[500005],ss[500005];
int fa[500005],son[500005];
int ans[300005];
int specialfa[300005];
stack<int> q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>=1;i--)
    {
        if(f[a[i]]) fa[i]=f[a[i]],f[a[i]]=i;
        if(!f[a[i]]) f[a[i]]=i,ggp[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[a[i]]) son[i]=s[a[i]];
        if(!s[a[i]]) s[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(!fa[i]) sf[i]=sf[i-1]+1;
        else sf[i]=sf[i-1];
        if(!son[i]) ss[i]=ss[i-1]+1;
        else ss[i]=ss[i-1];
    }
    specialfa[0]=1;
    for(int i=n;i>=1;i--)
    {
        if(!fa[i])
        {
            if(sf[n]-sf[i]==ss[n]-ss[i]) specialfa[i]=1;
        }
    }
    fa[0]=n+1;
    q.push(0);
    for(int i=1;i<=n;i++)
    {
        while(fa[q.top()]<=i) q.pop();
        if(!fa[i]) ans[a[i]]+=i-q.top();
        if(fa[i]&&(!specialfa[ggp[i]])) ans[a[i]]+=i-q.top(),q.push(i);
        if(fa[i]&&specialfa[ggp[i]]) q.push(i);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
}
