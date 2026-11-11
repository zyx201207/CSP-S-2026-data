


#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e9;
int n,m;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    __int128 cnt=0;
    vector<int> g;
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        char s;
        cin>>s;
        cnt+=a;
        for(int j=1;j<=a;j++)
        {
            int v=s-'a'+1;
            g.push_back(v);
        }
    }
    //cout<<(ll)cnt<<" ";
    ll ans=0;
    for(int i=0;i<=cnt/2;i++)
    {
        if(g[i]!=g[(ll)cnt-i-1]) ans++;//cout<<g[i]<<" "<<g[(ll)cnt-i-1]<<endl;//ans++;
    }
    cout<<ans;
    return 0;
}



/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+2;
struct
{
    ll r;
    ll l;
    int v;
}d[N];
int n;
ll dfs(int i,int j,ll q,ll p)
{
    if(q>=cnt/2||p<=cnt/2) return ans;

}
int main()
{
    cin>>n;
    __int128 cnt=0;
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        char s;
        cin>>s;
        d[i].l=cnt+1;
        d[i].r=cnt+a;
        cnt+=a;
        d[i].v=s-'a'+1;
    }
    cnt=1;
    for(int i=1;i<=n;i++)
    {
        j-=1;
        if(d[i].r>j) break;
        ll num=0;
        while(num<d[i].r-d[i].j+1)
        {

        }
    }
}*/
