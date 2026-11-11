#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,x,y) for(i=x;i<=y;i++)
#define rF(i,x,y) for(i=x;i>=y;i--)
const int N=2e5+5,MOD=1e9+7;
typedef pair<int,int> PII;
int n,a[N];
char c[N];
void solve()
{
    cin>>n;
    int i,l,r=n+1,suml=0,sumr=0,L=0,ans=0;
    F(i,1,n) cin>>a[i]>>c[i],L+=a[i];
    F(l,1,n) 
    {
        if(l!=1&&c[l]!=c[r]) ans+=min(suml+a[l],sumr)-suml;
        suml+=a[l];
        if(suml>L/2)
        {
            // cout<<l<<' '<<r<<' '<<ans<<'\n';
            F(i,l+1,r-1) if(c[l]!=c[i]) ans+=a[i];
            break;
        }
        while(sumr+a[r-1]<suml&&sumr+a[r-1]<L/2) 
        {
            r--;
            if(c[l]!=c[r]) ans+=a[r]; 
            sumr+=a[r];
        }
        // cout<<l<<' '<<r<<' '<<ans<<'\n';
        if(sumr<suml)
        {
            r--;
            if(c[l]!=c[r]) ans+=suml-sumr;
            sumr+=a[r];
            if(sumr>L/2)
            {
                F(i,l+1,r-1) if(c[r]!=c[i]) ans+=a[i];
                break;
            }
        }
    }
    cout<<ans;
    return; 
}
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0),cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--) {solve();}
}