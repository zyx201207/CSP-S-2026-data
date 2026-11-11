#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,d;
ll x[2000005],dp[5005][5005],s[5005][5005];
void dfs(int l,int i,int t)
{
    //cerr<<l<<" "<<i<<" ";
    for(int j=i+1;j<=n;++j)
    {
        if(x[j]-x[i]>d)
        {
            break;
        }
        //cerr<<l<<" "<<j<<" "<<dp[l][j]<<" "<<t+1<<"\n";
        if(t+1<dp[l][j])
        {
            dp[l][j]=t+1;
            s[l][j]=1;
            dfs(l,j,t+1);
        }
        else if(t+1==dp[l][j])
        {
            ++s[l][j];
            dfs(l,j,t+1);
        }
    }
    return;
}
void do_n3()
{
    ll ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;++i)
    {
        memset(dp[i],0x3f,(n+3)*sizeof(dp[i][0]));
        memset(s[i],0,(n+3)*sizeof(s[i][0]));
    }
    for(int i=1;i<=n;++i)
    {
        cin>>x[i];
    }
    for(int i=1;i<=n;++i)
    {
        dfs(i,i,0);
        for(int j=i;j<=n;++j)
        {
            //cerr<<s[i][j]<<"\n";
            if(s[i][j]==2)
            {
                ++ans;
            }
        }
    }
    /*for(int i=1;i<=n;++i)
    {
        cin>>x[i];
        dp[i][i]=1;
        s[i][i]=1;
    }
    for(int l=1;l<n;++l)
    {
        for(int i=1;i+l<=n;++i)
        {
            //cerr<<i<<" "<<i+l<<"\n";
            for(int k=i;k<i+l;++k)
            {
                if(x[k+1]-x[k]>d)
                {
                    continue;
                }
                int w=dp[i][k]+dp[k+1][i+l];
                //cerr<<k<<" "<<w<<" "<<",\n";
                if(w<dp[i][i+l])
                {
                    dp[i][i+l]=w;
                    s[i][i+l]=s[i][k]*s[k+1][i+l];
                }
                else if(w==dp[i][i+l])
                {
                    s[i][i+l]+=s[i][k]*s[k][i+l];
                }
            }
            if(s[i][i+l]==2)
            {
                ++ans;
            }
            //cerr<<dp[i][i+l]<<" "<<s[i][i+l]<<".\n";
        }
    }
    //cerr<<"\n";*/
    //cerr<<"\n";
    cout<<ans<<"\n";
    return;
}
void do_d()
{
    ll n,d,dis=0;
    cin>>n>>d;
    for(int i=1;i<=n;++i)
    {
        cin>>x[i];
    }
    if(n==1)
    {
        cout<<"0\n";
        return;
    }
    dis=x[2]-x[1];
    if(d<dis)
    {
        cout<<"0\n";
        return;
    }
    int k1=d/dis,k2=k1*2;
    //cerr<<d<<" "<<dis<<" "<<k1<<" "<<k2<<"\n";
    ++k1;--k2;
    if(k1>k2)
    {
        cout<<"0\n";
        return;
    }
    ll ans=0;
    for(int i=1;i+k1<=n;++i)
    {
        ans+=min<ll>(n,i+k2)-(i+k1)+1;
    }
    cout<<ans<<"\n";
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    ll t;
    cin>>c>>t;
    for(int i=1;i<=t;++i)
    {
        if(c>=1&&c<=10)
        {
            do_n3();
        }
        else if(c>=11&&c<=12)
        {
            do_d();
        }
        else
        {
            do_n3();
        }
    }
    return 0;
}
//stop doing do_n3 at 17:15
//stop doing do_d at 17:??
//finish do_n3 at 17:59