#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,a[5005],s[5005],e[5005],cnt,ans,num,minn=1e9;
void dfs(int x,int s,int e,int step)
{
    if(step>minn)
        return ;
    if(x==e)
    {
        if(minn==step)
            ans++;
        else if(minn>step)
            minn=step,ans=1;
        return ;
    }
    for(int i=x+1;i<=x+m;i++)
        dfs(i,s,e,step+1);
}
void solve()
{
    cnt=0,ans=0,num=0,minn=1e9;
    memset(s,0,sizeof s);
    memset(e,0,sizeof e);
    cin>>n>>m;
    s[++cnt]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1 && a[i]-a[i-1]>m)
            e[cnt]=i-1,s[++cnt]=i;
    }
    e[cnt]=n;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=s[i];j<=e[i];j++)
        {
            for(int k=j+1;k<=e[i];k++)
            {
                minn=1e9,ans=0;
                dfs(j,j,k,0);
                if(ans==2)
                    num++;
            }
        }
    }
    cout<<num<<endl;
}
void spe_sol()
{
    ans=0;
    memset(a,0,sizeof a);
    cin>>n>>m;
    for(int i=1;i<=2;i++)
        cin>>a[i];
    int ch=a[2]-a[1];
    for(int i=3;i<=n;i++)
		cin>>a[3];
    if(ch>m)
    {
        cout<<0<<endl;
        return ;
    }
    int k=m/ch;
    for(int l=k+2;l<=2*k && l<=n;l++)
    {
        ans+=n-l+1;
    }
    cout<<ans<<endl;
    return ;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(11<=c && c<=12)
    {
        while(t--)
            spe_sol();
	}
    else
        while(t--)
            solve();
    return 0;
}
