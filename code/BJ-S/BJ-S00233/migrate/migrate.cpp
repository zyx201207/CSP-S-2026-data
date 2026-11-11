#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,cnt=0,tot=0,len=0x3f3f3f3f;
int a[2000005];
void dfs(int x,int y,int l)
{
    if(l>len) return;
    if(x==y)
    {
        if(len>l)
        {
            len=l;
            tot=0;
        }
        tot++;
        return;
    }
    for(int i = x+1; i<=y; i++)
    {
        if(a[i]-a[x]>d) break;
        dfs(i,y,l+1);
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        map<int,int> mp;
        cnt++;
        cin>>n>>d;
        //if(cnt==3) cout<<n<<" "<<d<<endl;
        for(int i = 1; i<=n; i++)
        {
            cin>>a[i];
            mp[a[i]]=1;
            //if(cnt==3) cout<<a[i]<<endl;
        }
        if(c==11||c==12)
        {
            int tmp=d/abs(a[2]-a[1]);
            if(tmp<2) cout<<0<<endl;
            else cout<<max(0ll,n-2*tmp+1)<<endl;
        }
        else if(c==13||c==14)
        {
            int tmp,ans=0;
            for(int i = 1; i<=n; i++)
            {
                if(a[i]-a[1]<=d||a[n]-a[i]<=d) tmp=i;
            }
            for(int i = 1; i<tmp; i++)
            {
                if(mp[a[i]+d]==1&&mp[a[i]+d+d-1]==1) ans++;
                if(mp[a[i]+d-1]==1&&mp[a[i]+d+d-1]==1) ans++;
            }
            cout<<ans<<endl;
        }
        else
        {
            int sum=0;
            for(int i = 1; i<=n; i++)
            {
                for(int j = i+1; j<=n; j++)
                {
                    tot=0;
                    len=0x3f3f3f3f;
                    dfs(i,j,0);
                    if(tot==2)
                    {
                        sum++;
                        //cout<<i<<" "<<j<<endl;
                    }
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}

