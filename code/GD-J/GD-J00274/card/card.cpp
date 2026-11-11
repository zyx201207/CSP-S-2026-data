#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef char ch;
typedef string str;
const ll maxn=5e5+10,maxm=3e5+10;
ll n,m,a[maxn],lst[maxm],nxt[maxn],cnt[maxm],d[maxn],ans[maxm],dp[maxn];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],lst[a[i]]=i;
    lst[0]=nxt[n+1]=n+1;
    for(int i=n;i;i--)
    {
        cnt[a[i]]++;
        if(cnt[a[i]]>1) nxt[i]=i;
        else nxt[i]=nxt[i+1];
    }
    for(int i=1;i<=n;i++) dp[i]=1;
    for(int i=1;i<=n;i++) dp[lst[a[nxt[i]]]]+=dp[i];
    for(int i=1;i<=n;i++) d[i]+=dp[i],d[nxt[i]]-=dp[i];
    for(int i=1;i<=n;i++) d[i]+=d[i-1],ans[a[i]]+=d[i];
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}