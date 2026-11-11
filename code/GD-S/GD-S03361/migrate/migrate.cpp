#include<bits/stdc++.h>
using namespace std;
#define fileio
#define IOS
void ___()
{
#ifdef fileio
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
#endif
#ifdef IOS
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    #define endl '\n'
#endif
}
#define ll long long
typedef pair<int,int> pii;
const int _mxn=2e6+10;
int n,p[_mxn];
ll d,x[_mxn];
int mnd[_mxn],cnt[_mxn];
int main()
{
    ___();
    int __,_;
    cin>>__>>_;
    while(_--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        if(__==11||__==12)
        {
            ll dis=x[2]-x[1];
            
        }
        else if(__==13||__==14)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
            p[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
                mnd[j]=67676767,cnt[j]=0;
            queue<pii> q;
            q.push(make_pair(i,0));
            while(!q.empty())
            {
                auto cur=q.front();q.pop();
                int u=cur.first,s=cur.second;
                if(s>mnd[u])
                    continue;
                if(mnd[u]==67676767)
                    mnd[u]=s,cnt[u]=1;
                else if(s==mnd[u])
                    cnt[u]++;
                for(int j=u+1;j<=p[u];j++)
                {
                    q.push(make_pair(j,s+1));
                }
            }
            for(int j=i;j<=n;j++)
            {
                // cout<<cnt[j]<<" \n"[j==n];
                if(cnt[j]==2)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}