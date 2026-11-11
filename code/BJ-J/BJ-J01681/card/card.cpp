#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],lst[maxn],fst[maxn],cnt[maxn],pos=1,ans[maxn],val[maxn],num[maxn],cur=1,vis[maxn],tot;
inline bool cmp(int x,int y){return lst[x]<lst[y];}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!fst[a[i]]) fst[a[i]]=i;
        lst[a[i]]=i;
        cnt[a[i]]++;
    }
    for(int i=1;i<=m;i++) num[i]=i;
    sort(num+1,num+1+m,cmp);
    for(int i=1;i<=n;i++)
    {
        while(cnt[a[pos]]<=1&&pos<=n) pos++;
        val[fst[a[pos]]]++,val[lst[a[pos]]]--;
        cnt[a[i]]--;
        if(lst[num[cur]]==i&&cnt[num[m]]>=2)
        {
            vis[++tot]=cur;
        }
        if(pos==i) pos++;
    }
    for(int i=1;i<=tot;i++)
    {
        val[fst[num[m]]]+=val[fst[num[vis[i]]]];
        val[lst[num[m]]]+=val[lst[num[vis[i]]]];
        ans[num[vis[i]]]+=val[fst[num[vis[i]]]]+1;
        val[fst[num[vis[i]]]]=val[lst[num[vis[i]]]]=0;
    }
    for(int i=1;i<=n;i++) val[i]+=val[i-1];
    for(int i=1;i<=m;i++)
    {
        ans[i]+=max(0,lst[i]-val[lst[i]]);
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
