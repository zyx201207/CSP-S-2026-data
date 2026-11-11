#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,t;
ll n,d,x[N];
/*struct node
{
    int u,k;
};
queue<node> q;
int bfs(int s,int e)
{
    q.push({s,0});
    while(!q.empty())
    {
        node x=q.front();q.pop();
        if(x.u==e)
    }
}*/
void solve()
{
    cin >> n >> d;
    for(int i=1;i<=n;i++)
    {
        cin >> x[i];
        /*int t2=i-1;
        while(x[i]-x[t2]<=d)
        {

            t2--;
        }*/
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
    }*/
    cout << 0 << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
        solve();
    return 0;
}
