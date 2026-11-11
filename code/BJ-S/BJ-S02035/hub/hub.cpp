#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> ned_dfs,p[1000005],q[1000005];
int mi,d[1000005],v[1000005],di[1000005],v2[1000005];
queue<int> qu;
void dfs(int x)
{
    v2[x]=1;
    if(di[x]>di[mi])
        mi=x;
    for(int i=0,y=p[x].size();i<y;i++)
    {
        if(!v2[p[x][i]])
        {
            di[p[x][i]]=di[x]+1;
            dfs(p[x][i]);
        }
    }
    return;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,T,a,b,l,r,mid,fl,cnt,c,k,ma;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        l=0,r=n;
        for(int i=1;i<=n;i++)
        {
            p[i].clear();
        }
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            p[a].push_back(b);
            p[b].push_back(a);
            d[a]++;
            d[b]++;
        }
        while(l<=r)
        {
            mid=((l+r)>>1);
            cnt=fl=0;
            while(!qu.empty())
            {
                qu.pop();
            }
            for(int i=1;i<=n;i++)
            {
                v[i]=di[i]=v2[i]=0;
                q[i].clear();
                if(d[i]==1)
                    qu.push(i);
            }
            while(!qu.empty())
            {
                int x=qu.front();
                if(di[x]>=mid*2)
                    break;
                qu.pop();
                if(v[x])
                    continue;
                v[x]=1;
                q[di[x]].push_back(x);
                for(int i=0,y=p[x].size();i<y;i++)
                {
                    if((!v[p[x][i]])&&di[p[x][i]]==0)
                    {
                        di[p[x][i]]=di[x]+1;
                        qu.push(p[x][i]);
                    }
                }
            }
            for(int i=1;i<=n;i++)
            {
                cnt+=(!v[i]);
            }
            if(int(q[mid].size())<=k&&cnt==0)
                r=mid-1;
            else
                l=mid+1;
        }
        cout<<l<<"\n";
    }
    return 0;
}