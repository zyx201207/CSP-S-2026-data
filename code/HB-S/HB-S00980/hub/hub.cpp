#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,a[2234567],d[5005],f[5005],p[5005];
string ans="ccf",sum="no",num="mother";
vector<pair<int,int>> e[5234567];
void dji(int s,int n)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    memset(d,0x3f,sizeof(d));
    memset(f,0,sizeof(f));
    memset(p,0,sizeof(p));
    d[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        int len=pq.top().first,u=pq.top().second;
        pq.pop();
        for(int i=0;i<e[u].size();i++)
        {
            int vl=e[u][i].first,v=e[u][i].second;
            if(!p[v])
            {
                pq.push({vl,v});
                p[v]=1;
            }
            if(d[u]+vl<d[v])
            {
                d[v]=d[u]+vl;
                f[v]=0;
            }
            else if(d[u]+vl==d[v])
                f[v]+=1;
        }
    }
    for(int i=1;i<=n;i++)
        ans+=(f[i]==1);
    return ;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(abs(a[i]-a[j])<=d)
                {
                    e[i].push_back({1,j});
                    e[j].push_back({1,i});
                }
            }
        }
        for(int i=1;i<=n;i++)
            t++;
        cout<<ans<<sum<<num<<endl;
    }
	return 0;
}
