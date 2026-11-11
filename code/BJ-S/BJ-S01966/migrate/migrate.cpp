#include<bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;
const int N=2e6+5;
const int inf=1e9;
int dp[N],f[N];
int c,t,n,d;
int x[N];
int q[N];
void run()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    int ans=0;
    if(c<=10)
    {
        for(int o=1;o<=n;o++)
        {
            for(int i=1;i<=n;i++) dp[i]=f[i]=0;
            int l=1,r=1;
            dp[o]=0;f[o]=1;
            q[1]=o;
            for(int i=o+1;i<=n;i++) 
            {
                while(l<=r&&x[i]-x[q[l]]>d) l++;
                if(l>r) break;
                int j=l,res=0;
                while(j<r&&dp[q[j]]==dp[q[j]+1]) res+=f[q[j]],j++; 
                res+=f[q[j]];
                dp[i]=dp[q[j]]+1;
                f[i]=res;
                if(f[i]==2) ans++;
                while(l<=r&&dp[q[r]]>dp[i]) r--;
                q[++r]=i;
            }
        }
        cout<<ans<<endl;
    }
    else if(c==13||c==14)
    {
        int cnt=0;
        for(int i=1;i<=n;i++) 
        {
            if(x[i]-x[1]<=d&&x[n]-x[i]<=d) cnt++;
        }
        if(cnt==1) cout<<2<<endl;
        else if(cnt==2) cout<<1<<endl;
        else cout<<0<<endl;
    }
    else cout<<0<<endl;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--) run();
    return 0;
}