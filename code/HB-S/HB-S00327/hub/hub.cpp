#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=15;
int c,t,n,k,ans=1e18;
int fa[N];
vector<int>con[N];
bool put[N];
int F(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=F(fa[x]);
}
void Add(int x,int y)
{
    x=F(x),y=F(y);
    if(x!=y) fa[x]=y;
}
void Put(int t)
{
    if(t==n+1)
    {
        int num=0;
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<=n;i++)
            if(put[t]) num++;
        if(num!=k) return;
        for(int i=1;i<=n;i++)
            for(int u:con[i])
                if(put[u]) Add(i,u);
        int Now=0,Idx1=-1,Idx2=-1;
        for(int i=1;i<=n;i++)
            if(put[i])
            {
                int ff=F(i);
                if(ff!=Idx1)
                {
                    if(Idx1==-1) Idx1=ff;
                    else if(ff!=Idx2)
                    {
                        if(Idx2!=-1) return;
                        else Idx2=ff;
                    }
                    else return;
                }
            }
        return;
    }
    put[t]=0;
    Put(t+1);
    put[t]=1;
    Put(t+1);
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {

    }
}
