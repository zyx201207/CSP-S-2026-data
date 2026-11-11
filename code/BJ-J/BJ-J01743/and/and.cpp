#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,x,y) for(i=x;i<=y;i++)
#define rF(i,x,y) for(i=x;i>=y;i--)
const int N=2e5+5,MOD=1e9+7;
typedef pair<int,int> PII;
int n,m,a[N];
bool can[N];
void solve()
{
    int i,j;
    cin>>n>>m;
    F(i,1,n) cin>>a[i];
    rF(j,30,1)
    {
        int cnt=0;
        F(i,1,n) 
        {
            if(can[i]) continue;
            if(a[i]&(1<<j-1)) cnt++;
        }
        if(cnt<m) continue;
        F(i,1,n) if(!(a[i]&(1<<j-1))) can[i]=1;
    }
    int ans=(1<<30)-1;
    F(i,1,n) if(!can[i]) ans&=a[i];
    cout<<ans;
    return;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0),cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--) {solve();}
}