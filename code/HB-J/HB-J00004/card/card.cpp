#include<bits/stdc++.h>
using namespace std;
int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return x;
}
const int N=5e5+100;
int n,m;
int a[N],id[N],idx,fa[N],cnt[N],lst[N],ans[N],f[N],mp[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        fa[i]=i;
    }
    for(int i=n;i>=1;i--)
    {
        if(!lst[a[i]])
        {
            id[i]=++idx;
            mp[idx]=i;
            if(idx!=1)
            {
                int x=find(i+1);
                f[idx]=id[x];
            }
            lst[a[i]]=i;
            cnt[i]=1;
        }
        else
        {
            fa[i]=lst[a[i]];
            cnt[find(i)]++;
            lst[a[i]]=i;
        }
    }
    for(int i=idx;i>=1;i--)
    {
        ans[a[mp[i]]]=cnt[mp[i]];
        cnt[mp[f[i]]]+=cnt[mp[i]];
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
