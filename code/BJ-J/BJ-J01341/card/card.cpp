#include<iostream>
#include<vector>
using namespace std;
const int N=5e5+7;
int n,m,a[N],cnt[N],lp[N],sum[N];
vector<int> stats[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        int x=a[i];
        if(cnt[x]==0)
        {
            cnt[x]=1;
            lp[x]=i;
            stats[i]=stats[i+1];
            stats[i].push_back(x);
        }
        else{
            stats[i]=stats[lp[x]];
            stats[lp[x]].clear();
            lp[x]=i;
        }
        for(int j=0;j<stats[i].size();j++)
        {
            sum[stats[i][j]]+=1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d ",sum[i]);
        //cout<<sum[i]<<" ";
    }
    return 0;
}