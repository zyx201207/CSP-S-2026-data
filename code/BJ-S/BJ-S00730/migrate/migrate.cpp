#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXI=0x3FFFFFFFF;
array<int,5003>d;
array<array<int,5003>,5003>cnt;
vector<int>s[5003];
vector<int>w[5003];
array<ll,5003>p;
array<bool,5003>vis;
int c,t,n,m;
ll dl,ans;
ll csps_orz_rpplusplus(int sr,int ed)
{
    for(int i=0;i<303;i++)
    {
        cnt[i].fill(0);
    }
    d.fill(MAXI);
    vis.fill(0);
    int ccnt;
    queue<int>q;
    q.push(sr);
    q.push(0);
    int tt;
    while(!q.empty()&&tt<1000000)
    {
        tt++;
        int nu,nw;
        nu=q.front();
        q.pop();
        nw=q.front();
        q.pop();
        //vis[nu]=0;
        for(int i=0;i<s[nu].size();i++)
        {
            if(nw+w[nu][i]==d[i])
            {
                cnt[nu][i]++;
            }
            if(nw+w[nu][i]<d[i])
            {
                cnt[nu][i]=1;
                d[i]=nw+w[nu][i];
                //vis[s[nu][i]]=1;
                q.push(s[nu][i]);
                q.push(nw+w[nu][i]);
            }
        }
    }
    return 0;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>dl;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        /*for(int i=0;i<n+2;i++)
        {
            for(int j=0;j<n+2;j++)
            {
                d[i][j]=MAXI;
            }
        }*/
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(p[j]-p[i]<=dl)
                {
                    /*d[i][j]=j-i;
                    d[j][i]=j-i;*/
                    s[i].push_back(j);
                    w[i].push_back(j-i);
                    s[j].push_back(i);
                    w[j].push_back(j-i);
                }
                else
                {
                    break;
                }
            }
        }
        /*for(int i=1;i<=n;i++)
        {
            d[i][i]=0;
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(d[i][j]==d[i][k]+d[j][k])
                    {
                        cnt[i][j]++;
                    }
                    else if(d[i][j]<d[i][k]+d[j][k])
                    {
                        cnt[i][j]=1;
                        d[i][j]=d[i][k]+d[j][k];
                        d[j][i]=d[i][j];
                    }
                }
            }
        }*/
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                csps_orz_rpplusplus(i,j);
                if(cnt[i][j]==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
