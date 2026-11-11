#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e6;
int c,t,minn=0x3f3f3f3f;
ll n,d;
ll a[MAXN+5];
ll b[MAXN+5];
int dp[100][100];
int pd[100][100];
int f[100+5];
/*
void dfs(int x,int y,int dep)
{
    if(x==y)
        minn=min(minn,dep);
    for(int i=x+1;i<=y;)
}
*/
bool pdd()
{
    ll gap=a[2]-a[1];
    for(int i=2;i<=n;i++)
        if(a[i]-a[i-1]!=gap)
            return false;
    return true;
}
void dfs(int idx)
{
    if(idx==n+1)
    {
        int cnt=0;int st,ed;
        bool ft=false;
        for(int i=1;i<=n;i++)
            if(f[i])
                b[++cnt]=a[i];
        for(int i=1;i<=n;i++)
            if(!ft&&f[i])
                st=i,ft=true;
        ft=false;
        for(int i=n;i>=1;i--)
            if(!ft&&f[i])
                ed=i,ft=true;
        int ctkk=0;
        bool fkk=true;
        for(int i=2;i<=cnt;i++)
        {
            if(b[i]-b[i-1]<=d)
                ctkk++;
            else
            {
                fkk=false;
                break;
            }
        }
        if(fkk)
            dp[st][ed]=min(dp[st][ed],ctkk);
        return;
    }
    f[idx]=true;
    dfs(idx+1);
    f[idx]=false;
    dfs(idx+1);
    return;
}
void dfs1(int idx)
{
    if(idx==n+1)
    {
        int cnt=0;int st=0,ed=0;
        bool ft=false;
        for(int i=1;i<=n;i++)
            if(f[i])
                b[++cnt]=a[i];
        for(int i=1;i<=n;i++)
            if(!ft&&f[i])
                st=i,ft=true;
        ft=false;
        for(int i=n;i>=1;i--)
            if(!ft&&f[i])
                ed=i,ft=true;
        int ctkk=0;
        bool fkk=true;
        for(int i=2;i<=cnt;i++)
        {
            if(b[i]-b[i-1]<=d)
                ctkk++;
            else
            {
                fkk=false;
                break;
            }
        }
        if(fkk&&ctkk==dp[st][ed])
            pd[st][ed]++;
        return;
    }
    f[idx]=true;
    dfs1(idx+1);
    f[idx]=false;
    dfs1(idx+1);
    return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//cout<<1000000000000000000-999997142608141581 ;
    cin>>c>>t;
    while(t--)
    {
        memset(f,0,sizeof(f));
        memset(pd,0,sizeof(pd));
        memset(dp,0x3f,sizeof(dp));
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(pdd())
        {
            ll gap=a[2]-a[1];
            if(gap>=d)
                cout<<"0\n";
            else
                cout<<max(n-2*(d/gap)+1,(1LL*0))<<endl;
            //cout<<11;
        }
        else
        {
            dfs(1);
            dfs1(1);
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                    if(pd[i][j]==2)
                        ans++;
            }
            /*for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    cout<<"["<<i<<","<<j<<"]="<<dp[i][j]<<" ";
                }
                cout<<endl;
            }*/
            cout<<ans<<endl;
        }
    }
	return 0;
}














