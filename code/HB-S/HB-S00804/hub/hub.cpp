#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
struct nod
{
    int nxt;
    int to;
};
nod b[2000050];
int h[1000050];
int cnt;
bool pd[1050];
int bcj[1050];
int ans;
void ccc(int x,int y)
{
    ++cnt;
    b[cnt].to=y;
    b[cnt].nxt=h[x];
    h[x]=cnt;
    return ;
}
int cz(int d)
{
    return (bcj[d]==d?d:bcj[d]=cz(bcj[d]));
}
int ff(int d,int fa)
{
    if(pd[d])return 0;
    int ma=0;
    int i;
    i=h[d];
    while(i!=-1)
        {
            if(b[i].to==fa)
                {
                    i=b[i].nxt;
                    continue;
                }
            ma=max(ma,ff(b[i].to,d)+1);
            i=b[i].nxt;
        }
    return ma;
}
void g()
{
    int i,j;
    i=1;
    while(i<=n)
        {
            bcj[i]=i;
            ++i;
        }
    i=1;
    while(i<=n)
        {
            if(pd[i])
                {
                    j=h[i];
                    while(j!=-1)
                        {
                            if(pd[b[j].to])
                                {
                                    bcj[cz(i)]=cz(b[j].to);
                                }
                            j=b[j].nxt;
                        }
                }
            ++i;
        }
    int gs=0;
    i=1;
    while(i<=n)
        {
            if(pd[i]&&bcj[i]==i)++gs;
            ++i;
        }
    if(gs>2)return ;
    int jg=0;
    i=1;
    while(i<=n)
        {
            jg=max(jg,ff(i,0));
            ++i;
        }
    ans=min(ans,jg);
    return ;
}
void f(int d,int ss)
{
    if(ss==k+1)return ;
    if(d==n+1)
        {
            g();
            return ;
        }
    pd[d]=0;
    f(d+1,ss);
    pd[d]=1;
    f(d+1,ss+1);
    return ;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    int i,j;
    int x,y;
    while(t!=0)
        {
            memset(h,-1,sizeof(h));
            ans=1e9+10;
            cnt=0;
            cin>>n>>k;
            i=1;
            while(i<n)
                {
                    cin>>x>>y;
                    ccc(x,y);
                    ccc(y,x);
                    ++i;
                }
            f(1,0);
            cout<<ans<<'\n';
            --t;
        }
    return 0;
}