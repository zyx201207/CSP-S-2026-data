#include <iostream>
using namespace std;
int a[2000006];int en,cnt;int n,d;

void dfs(int s,int p)
{
    if(s>2)
    {
        if(p==en)
        {
            cnt++;
        }
        return;
    }
    for(int i=p; a[i]-a[p]<=d&&i<=n; i++)
    {
        dfs(s+1,i);
    }
    return;
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int r=1; r<=t; r++)
    {
        int ans=0;
        cin>>n>>d;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        for(int i=1; i<n-1; i++)
        {
            cnt=0,en=i+3;
            dfs(1,i);
            if(cnt==2)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }



    return 0;
}
