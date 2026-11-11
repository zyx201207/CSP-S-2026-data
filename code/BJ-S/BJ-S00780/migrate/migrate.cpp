#include<bits/stdc++.h>
using namespace std;
int x[2000010];
int num=0,minx=INT_MAX;
int n,d;
int path=0;
void dfs(int cur,int stop)//qiu zui duan lu
{
    if(cur==stop)
    {
        minx=min(minx,path);
        return ;
    }
    int j=cur+1;
    while(j<=n&&abs(x[cur]-x[j])<=d)
    {
        path++;
        dfs(j,stop);
        path--;
        j++;
    }
}
int step=0;
void sol(int cur,int stop)
{
    if(cur==stop)
    {
        if(step==minx) num++;
        return ;
    }
    int j=cur+1;
    while(j<=n&&abs(x[cur]-x[j])<=d)
    {
        step++;
        sol(j,stop);
        step--;
        j++;
    }
}
int main()
{       //--  --  --        __  _____               __     _     --
       //|   |   |__   |   |      |     /\    /\   |      / \   |
      // |   |   |     |   |--    |    /  \  /  \  |--   /---\  |
     //   --  -- |   , |__ |__    |   /    \/    \ |__  /     \  --
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {

        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                num=0;
                minx=INT_MAX;
                dfs(i,j);//qiu zui duan lu jing
                sol(i,j);//qiu zui duan lu jing you duo shao tiao
                if(num==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
