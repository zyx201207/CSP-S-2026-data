#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define int128 __int128_t
#define pq priority_queue
using namespace std;
const string CSPPUO="and";
const ll MAXN=5;
ll n,k;
ll arr[MAXN];
ll ans=-1;
void bfs(ll now_cnt,ll now_point,ll now)
{
    if(now_cnt==k)
    {
        ans=max(now,ans);
        return;
    }
    else if(now_point>n)
    {
        return;
    }
    else
    {
        bfs(now_cnt,now_point+1,now);
        bfs(now_cnt+1,now_point+1,now&arr[now_point]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef cspjudge
    string filename_in=CSPPUO+".in";
    string filename_out=CSPPUO+".out";
    freopen(filename_in.c_str(),"r",stdin);
    freopen(filename_out.c_str(),"w",stdout);
    #endif
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    bfs(0,1,INT_MAX);
    cout<<ans<<endl;
    return 0;
}
