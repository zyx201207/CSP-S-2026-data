#include<bits/stdc++.h>
using namespace std;
long long a[2000000+5],ans[5000+5][5000+5][2],n,d;
void dfs(int f,int t)
{
    long long x=1e18,y=1;
    if(t-f==1)
    {
        if(a[t]-a[f]<=d)
        {
            ans[f][t][0]=1;
            ans[f][t][1]=1;
        }
        return;
    }
    for(int i=f+1;i<t;++i)
    {
        if(ans[f][i][0]==1e18)
            dfs(f,i);
        if(ans[i][t][0]==1e18)
            dfs(i,t);
        int z=ans[f][i][0]+ans[i][t][0];
        if(z==x)
            y++;
        else if(z<x)
        {
            x=z;
            y=1;
        }
    }
    ans[f][t][0]=x;
    ans[f][t][1]=y;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        memset(ans,1e18,sizeof ans);
        cin>>n>>d;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        dfs(1,n);
        long long cnt=0;
        for(int i=1;i<=n;++i)
            for(int j=i+1;j<=n;++j)
                if(ans[i][j][1]==2)
                    cnt++;
        cout<<cnt<<"\n";
    }
	return 0;
}

