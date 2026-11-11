#include<bits/stdc++.h>
using namespace std;
int c,t,ans;
int dis[2000006],minn[2000006],ci[2000006];
int n,d;
void dfs(int x,int depth,int d)
{
    //cout<<x<<" "<<depth<<endl;
    if(depth<minn[x])
    {
        minn[x] = depth;
        ci[x] = 1;
    }
    if(depth = minn[x])
    {
        ci[x]++;
    }
    int num = 1;
    if(x == n)
    {

        return;
    }
    for(int i=1;i<=d;i++)
    {
        //cout<<"pan:"<<x<<" "<<dis[x]<<" "<<i<<" "<<num<<" "<<dis[x+num]<<endl;
        if(dis[x]+i==dis[x+num]&&num+x<=n)
        {
            dfs(x+num,depth+1,d);
            //cout<<x<<" "<<depth<<endl;
            num++;
        }
        else if(num+x>n)
        {
            break;
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans = 0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>dis[i];
            minn[i] = INT_MAX;
        }
        dfs(1,0,d);
        for(int i=1;i<=n;i++)
        {
            //cout<<ci[i]<<" ";
            ci[i]--;
            if(ci[i]==2)
            ans++;
        }
        //cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
