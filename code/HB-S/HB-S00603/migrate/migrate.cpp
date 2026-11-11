#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int n,d;
int cnt,minn=1e9;
void dfs(int x,int e,int cur)
{
    //cout<<x<<endl;
    if(x==e)
    {
        //cout<<cur<<" ";
        if(cur<minn)
        {
            cnt=1;
            minn=cur;
        }
        else if(cur==minn)
        {
            cnt++;
        }
        //cout<<cnt<<endl;
        return ;
    }
    if(cur>minn)
    {
        //cout<<endl;
        return ;
    }
    if(a[x]>e)
    {
        //cout<<endl;
        return ;
    }
    for(int i=x+1;i<=n;i++)
    {
        if(a[i]-a[x]<=d)
        {
            //cout<<x<<" ->"<<i<<" ->";
            dfs(i,e,cur+1);
        }
        else
        {
            break;
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                cnt=0;
                minn=1e9;
                dfs(i,j,0);
                if(cnt==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
