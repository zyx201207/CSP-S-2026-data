#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
ll n,m;
ll a[2000050];
struct nod
{
    int nxt;
    int to;
};
nod b[25000050];
int h[5050];
int cnt;
queue<int> dl;
int jg[5050];
int gs[5050];
ll ans;
void ccc(int x,int y)
{
    ++cnt;
    b[cnt].to=y;
    b[cnt].nxt=h[x];
    h[x]=cnt;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    int i,j;
    int d;
    while(t!=0)
        {
            if(c==11||c==12)
                {
                    cin>>n>>m;
                    i=1;
                    while(i<=n)
                        {
                            cin>>a[i];
                            ++i;
                        }
                    i=1;
                    while(i<n)
                        {
                            if(a[i+1]-a[1]>m)break;
                            ++i;
                        }
                    int cd=i-1;
                    if(cd<2)cout<<'0'<<'\n';
                    else cout<<max(1ll*0,n-cd-cd+1)<<'\n';
                    --t;
                    continue;
                }
            memset(h,-1,sizeof(h));
            cnt=0;
            ans=0;
            cin>>n>>m;
            i=1;
            while(i<=n)
                {
                    cin>>a[i];
                    ++i;
                }
            i=1;
            while(i<=n)
                {
                    j=i+1;
                    while(j<=n&&a[j]-a[i]<=m)
                        {
                            ccc(i,j);
                            ++j;
                        }
                    ++i;
                }
            i=1;
            while(i<=n)
                {
                    memset(jg,63,sizeof(jg));
                    memset(gs,0,sizeof(gs));
                    jg[i]=0;
                    gs[i]=1;
                    dl.push(i);
                    while(!dl.empty())
                        {
                            d=dl.front();
                            dl.pop();
                            j=h[d];
                            while(j!=-1)
                                {
                                    if(jg[b[j].to]==jg[d]+1)gs[b[j].to]+=gs[d];
                                    if(jg[b[j].to]>jg[d]+1)
                                        {
                                            jg[b[j].to]=jg[d]+1;
                                            gs[b[j].to]=gs[d];
                                            dl.push(b[j].to);
                                        }
                                    j=b[j].nxt;
                                }
                        }
                    j=i;
                    while(j<=n)
                        {
                            if(gs[j]==2)++ans;
                            ++j;
                        }
                    ++i;
                }
            cout<<ans<<'\n';
            --t;
        }
    return 0;
}