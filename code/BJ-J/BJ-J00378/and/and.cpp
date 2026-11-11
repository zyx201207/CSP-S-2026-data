#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int b[maxn][35];
bool flag[maxn];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        int x=a[i];
        int cnt=0;
        while(x)
        {
            b[i][++cnt]=x%2;
            x/=2;
        }
        flag[i]=1;
    }
    int ans=0;
    for(int i=32; i>=1; i--)
    {
        int cnt=0;
        for(int j=1; j<=n; j++)
        {
            if(flag[j]&&b[j][i]==1)cnt++;
        }
        if(cnt<m)ans*=2;
        else
        {
            for(int j=1; j<=n; j++)
            {
                if(flag[j]&&b[j][i]==0)flag[j]=0;
            }
            ans*=2;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
