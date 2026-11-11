#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int i,w[5005][5005],j,ans[5005][5005],w1[5005],a[5005],h[5000005],o[5000005];
struct dian
{
    int n;
    int d;
    int f;
    int f1;
};
struct cmp1
{
    bool operator()(const dian &a,const dian &b)const{
        return a.d>b.d;
    }
};
void dis(int s)
{
    priority_queue<dian,vector<dian>,cmp1>u;
    dian g;
    int i;
    g.d=0;
    g.n=s;
    g.f=0;
    g.f1=0;
    u.push(g);
    int f[505];
    bool v[505];
    for(i=1;i<=m;i++)
    {
        v[i]=0;
        f[i]=0;
    }
    while(!u.empty())
    {
        dian e=u.top();
        //cout<<e.n<<" "<<e.d<<endl;
        u.pop();
        if(!v[e.n])
        {
            f[e.n]=e.f;
            for(i=f[e.n];i;i=f[i])
            {
                ans[i][e.n]=e.d-ans[s][i];
                ans[e.n][i]=ans[i][e.n];
            }
            v[e.n]=1;
            for(i=1;i<=m;i++)
            {
                if(v[i]!=1&&w[e.n][i]!=0)
                {
                    g.d=e.d+w[e.n][i];
                    g.n=i;
                    g.f=e.n;
                    g.f1=w[e.n][i];
                    u.push(g);
                }
            }
        }
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(i=1;i<=m;i++)
    {
        cin>>w1[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        for(j=1;j<=a[i];j++)
        {
            cin>>h[j]>>o[j];
        }
        for(j=1;j<=a[i]-1;j++)
        {
            for(int z=j+1;z<=a[i];z++)
            {
                if(w[h[j]][h[z]]==0)
                {
                    w[h[j]][h[z]]=o[j]+o[z];
                    w[h[z]][h[j]]=w[h[j]][h[z]];
                }
                else
                {
                    w[h[j]][h[z]]=min(w[h[j]][h[z]],o[j]+o[z]);
                    w[h[z]][h[j]]=w[h[j]][h[z]];
                }
            }
        }
    }
    /*for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=1;i<=q;i++)
    {
        int s,t;
        cin>>s>>t;
        if(s==t)
        {
            cout<<0<<endl;
        }
        else if(ans[s][t]!=0)
        {
            cout<<ans[s][t]+w1[s]+w1[t]<<endl;
        }
        else
        {
            dis(s);
            cout<<ans[s][t]+w1[s]+w1[t]<<endl;
        }
    }
    /*for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
