#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n=0,m=0;
long long ans=0;
void dfs(long long num,long long sum,long long a1)
{
    if(num>n||((n-num+sum+1)<m))
    {
        return;
    }
    if(sum==m)
    {

        ans=max(ans,a1);
        return;
    }
    if(a1<ans)return;
    dfs(num+1,sum+1,a1&a[num+1]);
    dfs(num+1,sum,a1);

}
int main()
{
    freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
   }
 dfs(1,1,a[1]);
dfs(1,0,INT_MAX);
    cout<<ans;
    return 0;
}

