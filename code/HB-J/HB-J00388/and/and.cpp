#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005,LGN=31;
int n,m,Ans,a[N];
int ch[N][2],cnt[N],idx=1,num[N][LGN];
vector<int>Produce(int x)
{
    vector<int>v;
    for(int i=0;i<LGN;i++)
        v.push_back(x%2),x/=2;
    reverse(v.begin(),v.end());
    return v;
}
void Insert(int X)
{
    vector<int>v=Produce(X);
    int u=1;
    for(int x:v)
    {
        if(!ch[u][x]) ch[u][x]=++idx;
        u=ch[u][x],cnt[u]++;
    }
}
void Getnum(int u,int dep,int Zhi)
{
    num[u][dep]=Zhi*cnt[u];
    if(dep<LGN-1)
    {
        if(ch[u][0]) Getnum(ch[u][0],dep+1,0);
        if(ch[u][1]) Getnum(ch[u][1],dep+1,1);
        for(int i=dep;i<LGN;i++)
        {
            if(ch[u][0]) num[u][i]+=num[ch[u][0]][i];
            if(ch[u][1]) num[u][i]+=num[ch[u][1]][i];
        }
    }
}
int MaxAnd(int X)
{
    vector<int>v=Produce(X);
    int u=1,dep=0,ans=0;
    for(int x:v)
    {
        int AddIdx;
        if(x==0) AddIdx=u;
        else
        {
            if(!ch[u][1]) return ans;
            else AddIdx=ch[u][1];
        }
        if(num[AddIdx][dep]>=m-1) ans+=(1<<(LGN-dep));
        dep++,u=AddIdx;
    }
    return ans;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) Insert(a[i]);
    Getnum(1,0,0);
    for(int i=1;i<=n;i++) Ans=max(Ans,MaxAnd(a[i]));
    cout<<Ans;
}
