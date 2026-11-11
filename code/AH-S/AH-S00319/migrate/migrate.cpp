#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll a[N],ans;

//void dfs(int x,ll now)
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int c,T;
    cin>>c>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        int n,d;cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        ans=0;

        cout<<ans<<'\n';
    }
    return 0;
}
