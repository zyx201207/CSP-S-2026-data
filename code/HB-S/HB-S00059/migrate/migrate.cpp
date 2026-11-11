/*

0 1 2 3 4 5 6 7 8 9 ...                 n-1
------------------------------------------>
x0x1x2x3x4x5x6x7x8x9 ...                xn-1

*/

#include <bits/stdc++.h>

using namespace std;
#define vec vector
#define For(n) for(int i=0;i<n;++i)
#define int long long

struct island
{
    int x;
    vec<int> bigger;
};

bool in(int x,vec<int> v){
    return (find(v.begin(),v.end(),x)!=v.end());
}

bool in(int x,queue<int> p){
    auto q=p;
    vec<int> temp;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        temp.push_back(k);
    }
    return in(x,temp);
}

int solve(){
    int n,d;
    cin>>n>>d;
    vec<island> islands(n);
    For(n) cin>>islands[i].x;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(islands[j].x-islands[i].x<=d){
                islands[i].bigger.push_back(j);
            }else break;
        }
    }
    int ans=0;

    for(int i=1;i<=n-1;++i){
        queue<int>q;
        vec<pair<int,int>> dist(n+1,pair<int,int>(LONG_LONG_MAX,0));
        q.push(i);
        dist[i].first=0;
        dist[i].second=1;
        while (!q.empty())
        {
            auto cx = q.front();
            q.pop();
            for(auto nx:islands[cx].bigger){
                int k = dist[cx].first+1;
                if(k<dist[nx].first){
                    dist[nx].first=k;
                    dist[nx].second=1;
                    if(!in(nx,q)) q.push(nx);
                }else if (k==dist[nx].first)
                {
                    dist[nx].second++;
                    if(!in(nx,q)) q.push(nx);
                }
            }
        }
        for(int j=i+1;j<=n;++j){
            if(dist[j].second==2){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto f1 = freopen("migrate.in","r",stdin);
    auto f2 = freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}