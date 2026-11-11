#include<bits/stdc++.h>
using namespace std;
#define Int long long
Int a[200005];
Int mi[31];
Int n,m;
struct node{
    bool b[31];
}cx[200005];
Int cnt[31];
bool vis[200005];
bool mvis[31];
bool cmp(Int a,Int b)
{
    return a>b;
}
void re()
{
    memset(cnt,0,sizeof(cnt));
    for(Int i=1;i<=n;i++)
    {
        Int q=a[i];
        if(vis[i])
        {
            continue;
        }
        for(Int j=30;j>=0;j--)
        {
            if(q>=mi[j])
            {
                q-=mi[j];
                cx[i].b[j]=1;
                cnt[j]++;
            }
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    mi[0]=1;
    for(Int i=1;i<=30;i++)
    {
        mi[i]=mi[i-1]*2;
    }
    for(Int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    re();
    Int ans=0;
    while(1)
    {
        Int q=ans,res;
        for(Int i=30;i>=0;i--)
        {
            if(cnt[i]>=m&&mvis[i]==0)
            {
                ans+=mi[i];
                res=i;
                mvis[i]=1;
                break;
            }
        }
        if(q!=ans)
        {
            for(Int i=1;i<=n;i++)
            {
                if(cx[i].b[res]==0)
                {
                    vis[i]=1;
                }
            }
            re();
        }
        else{
            break;
        }
    }
    cout<<ans;
    return 0;
}
