#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,x,ans;
bool b[200005];
int s[200005][35];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        for(int j=30;j>=0;j--)
        {
            if(x>=(1<<j))
            {
                s[i][30-j]=1;
                x-=(1<<j);
            } 
            else s[i][30-j]=0;
        }
    }
    for(int i=30;i>=0;i--)
    {
        int id=30-i;
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(!b[j]) cnt+=s[j][id];
        }
        if(cnt<m) continue;
        ans+=(1<<i);
        for(int j=1;j<=n;j++)
        {
            if(s[j][id]==0) b[j]=true;
        }
    }
    cout<<ans<<endl;
    return 0;
}