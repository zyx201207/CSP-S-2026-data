#include <bits/stdc++.h>
using namespace std;
const int N=5005;
using ll=long long;
int c;
int n,ans;
ll D,x[N];
vector<int> e[N];
int in[N];
pair<int,int> dp[N];//{dist,cnt}
void calc(int S)
{
    for(int i=S;i<=n;i++)e[i].clear();
    for(int i=S;i<=n;i++)dp[i]={1e9,0};
    memset(in,0,sizeof in);

    for(int u=S;u<=n;u++)
    {
        for(int v=u+1;v<=n;v++)
        {
            if(x[v]-x[u]<=D)e[u].push_back(v),in[v]++;
            else break;
        }
    }

    queue<int> q;q.push(S);
    dp[S]={0,1};
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int v:e[u])
        {
            if(dp[v].first>dp[u].first+1)
            {
                dp[v].first=dp[u].first+1;
                dp[v].second=dp[u].second;
            }
            else if(dp[v].first==dp[u].first+1)
                dp[v].second+=dp[u].second;
            in[v]--;
            if(!in[v])q.push(v);
        }
    }

    for(int i=S;i<=n;i++)if(dp[i].second==2)ans++;
}
void solve()
{
    cin>>n>>D;
    for(int i=1;i<=n;i++)cin>>x[i];

    ans=0;
    for(int i=1;i<=n;i++)calc(i);
    cout<<ans<<endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;cin>>c>>T;
    while(T--)solve();
    return 0;
}
/*
cd migrate
ulimit -s unlimited
g++ migrate.cpp -o migrate -O2 -std=c++14 -static -Wall
time ./migrate
*/