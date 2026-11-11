#include<bits/stdc++.h>
using namespace std;
const int M=5*1e5;
int x[M];
int ct=0,minn=INT_MAX;
int n,d;
void dfs(int v,int y,int cnt)
{

    if(v>n||y>n)
    {
        return ;
    }
    if(cnt>minn)
    {
        return ;
    }
    if(x[v]>x[y])
    {
        return ;
    }
    if(x[v]==x[y])
    {
        if(cnt==minn)
        {
            ct++;
        }
        else if(cnt<minn)
        {
            ct=0;
            minn=cnt;
        }
    }

    for(int i=d;i>=1;i--)
    {
        int p=v+1;

        while(x[p]<=x[v]+i)
        {
            p++;
            if(p>n)
            {
                break;
            }
        }
        if(p-1==v+1)
        {
            return;
        }
        if(p>n)
        {
            continue;
        }
        p--;
        dfs(p,y,cnt+1);
    }
    return ;

}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int ANS=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                dfs(i,j,0);
                if(ct==2)
                {
                    ANS++;
                }
                ct=0;
                minn=INT_MAX;
            }
        }
        cout<<ANS<<endl;
    }
    return 0;
}
