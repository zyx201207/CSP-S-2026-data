#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> a[N];
int sz[N],ms[N],k,h[N],mh[N],f[N],v[N],r,n;
void init(int c,int fa=0)
{
    int i;
    sz[c]=1;
    mh[c]=0;
    h[c]=h[fa]+1;
    f[c]=fa;
    for(i=0;i<a[c].size();i++)
    {
        if(a[c][i]==fa) continue;
        init(a[c][i],c);
        sz[c]+=sz[a[c][i]];
        mh[c]=max(mh[c],mh[a[c][i]]+1);
        ms[c]=max(ms[c],sz[a[c][i]]);
    }
}
bool ch(int o)
{
    int i;
    if(mh[r]<o)
    {
        return 1;
    }
    for(i=1;i<=n;i++)
    {
        v[i]=0;
    }
    priority_queue<pair<int,int> > q;
    int now=0;
    for(i=1;i<=n;i++)
    {
        if(mh[i]==o)
        {
            // cerr<<o<<":"<<i<<"\n";
            q.push({h[i],i});
            v[i]=1;
            now++;
        }
    }
    while(q.size()>2)
    {
        if(now>k)
        {
            return 0;
        }
        int c=q.top().second;
        q.pop();
        if(v[c])
        {
            continue;
        }
        if(v[f[c]]!=0)
        {
            now++;
            q.push({h[f[c]],f[c]});
            v[f[c]]=1;
        }
    }
    if(q.size()==1) return 1;
    int r1=q.top().second;q.pop();
    int r2=q.top().second;q.pop();
    // cerr<<o<<":"<<r1<<" "<<r2<<" "<<r<<" "<<f[r1]<<" "<<f[r2]<<"\n";
    int fr1=r1,fr2=r2;
    while(f[r1]!=r)
    {
        r1=f[r1];
    }
    while(f[r2]!=r)
    {
        r2=f[r2];
    }
    int mm=-1;
    for(i=0;i<a[r].size();i++)
    {
        if(a[r][i]==r1||a[r][i]==r2) continue;
        mm=max(mm,mh[a[r][i]]);
    }
    mm++;
    // cerr<<mm<<" "<<now<<'\n';
    int z=max(0,min(h[fr1],h[fr2])-(1+o-mm));
    return now+z<=k;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int i,j,m,l,x,y,s=0,o,c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            mh[i]=0;
            a[i].clear();
        }
        for(i=1;i<n;i++)
        {
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        h[1]=1;
        init(1);
        for(i=1;i<=n;i++)
        {
            if(ms[i]<=n/2&&sz[i]>n/2)
            {
                r=i;
            }
            // cout<<i<<":"<<ms[i]<<" "<<sz[i]<<"\n";
            mh[i]=0;
        }
        h[r]=1;
        init(r);
        // cout<<r<<":";
        // for(i=1;i<=n;i++)
        // {
        //     cout<<mh[i]<<" ";
        // }
        // cout<<"\n";
        l=1;
        int R=n;
        while(l<R)
        {
            int mid=l+R>>1;
            // cerr<<l<<" "<<R<<"\n";
            if(ch(mid))
            {
                R=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        cout<<l<<"\n";
    }
    return 0;
}