#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int a,d;
int sum=0,edsum=0;
int minn=-1;
int x[2000005];
void dfs(int start,int ed,int wz,int cs)
{
    if(sum>2)
    {
        return;
    }
    if(wz==ed)
    {
        if(minn==-1)
        {
            sum=1;
            minn=cs;
        }
        else
        {
            if(minn==cs)
            {
                sum++;
            }
        }
        return;
    }
    for(int i=ed;i>=wz+1;i--)
    {
        if(x[i]-x[wz]<=d)
        {
            dfs(start,ed,i,cs+1);
            if(sum>2) return;
        }
    }
    return;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        edsum=0;
        cin>>a>>d;
        for(int i=1;i<=a;i++) cin>>x[i];
        for(int i=1;i<=a;i++)
        {
            for(int j=i+1;j<=a;j++)
            {
                minn=-1;
                sum=1;
                dfs(i,j,i,0);
                if(sum==2) edsum++;
            }
        }
        cout<<edsum<<"\n";
    }
    return 0;
}
