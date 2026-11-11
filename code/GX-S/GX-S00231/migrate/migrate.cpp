#include<bits/stdc++.h>
#define m(a,b) memset(a,b,sizeof a)
using namespace std;
const int N=2e6+5;
int n,d;
int c,T,ans=INT_MAX;
int a[N],b[N];
void dfs(int step,int x,int ed)
{
    if(x==ed)
    {
        ans=min(ans,step);
        b[ans]++;
    }
    if(step>ans) return;
    for(int i=x+1;i<=ed;i++)
    {
        if(a[i]-a[x]<=d)
        {
            dfs(step+1,i,ed);
        }
        else break;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        m(a,0);
        m(b,0);
        int sum=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                dfs(0,i,j);
                if(b[ans]>1) sum++;
                m(b,0);
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}
