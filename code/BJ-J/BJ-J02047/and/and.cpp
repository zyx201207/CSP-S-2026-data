#include <iostream>
#include <algorithm>
using namespace std;
int a[1000005];int n,m,v[100],ans=0;
void dfs(int t,int s)
{
    if(t>m)
    {
        ans=max(ans,s);
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(!v[i])
        {
            v[i]=1;
            dfs(t+1,a[i]&s);
            v[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    if(n<25)
    {
        for(int i=1; i<=n; i++)
        {
            dfs(1,a[i]);
        }
        cout<<ans;
    }
    else{
        sort(a+1,a+1+n,greater<int>());
        ans=a[1];
        for(int i=2; i<=m; i++)
        {
            ans&=a[i];
        }
        cout<<ans;
    }



    return 0;
}
