#include<iostream>
#include<vector>
using namespace std;
int n,m;
long long x;
int maxn=0,fl=0;
int f[200005][35];
int s[35];
int p[35];
long long ans;
vector<int> q;
void gointoit(int i,long long x)
{
    int nnum=0;
    while(x)
    {
        f[i][nnum]=x%2;
        if(x%2==1) s[nnum]++;
        nnum++;
        x>>=1;
    }
    maxn=max(maxn,nnum-1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        gointoit(i,x);
    }
    for(int i=maxn;i>=0;i--)
    {
        if(s[i]>=m) fl++,p[fl]=i;
    }
    if(fl==0)
    {
        cout<<0;
        return 0;
    }
    int mi=1,totnum=0;
    for(int i=1;i<=n;i++)
    {
        if(f[i][p[1]]) q.push_back(i),totnum++;
    }
    ans+=(1<<p[mi]);
    while(totnum>=m&&mi<fl)
    {
        mi++;
        int cal=0;
        for(int i=0;i<q.size();i++)
        {
            if(q[i]==-1) continue;
            if(f[q[i]][p[mi]]) cal++;
        }
        if(cal<m) continue;
        ans+=(1<<p[mi]);
        totnum=cal;
        for(int i=0;i<q.size();i++)
        {
            if(q[i]==-1) continue;
            if(!f[q[i]][p[mi]]) q[i]=-1;
        }
    }
    cout<<ans;
}
