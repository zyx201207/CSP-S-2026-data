#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node
{
    int edge;
    LL val;
}tmp;
struct slv1
{
    int x,y,num;
    bool operator<(const slv1 a)const
    {
        return x<a.x;
    }
}qn[500010];
vector<node> s[510010];
int test,n,m,d,q;
LL w[500010],r[2000],qa[500010];
queue<node> nt;
void build(int x,int y,LL v)
{
    tmp.val=v;
    tmp.edge=y;
    s[x].push_back(tmp);
    tmp.edge=x;
    s[y].push_back(tmp);
    return;
}
void solve1(int x,int fm,LL p)
{
    int i,j;
//    cout<<x<<' ';
    r[x]=p;
    for(i=0; i<s[x].size(); i++)
    {
        if(s[x][i].edge!=fm)
            solve1(s[x][i].edge,x,p+s[x][i].val);
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int i,j,k,x,y;
    LL t;
    cin>>test>>n>>m>>d>>q;
    for(i=1; i<=m; i++) cin>>w[i];
    for(i=1; i<=n; i++)
    {
        cin>>k;
        for(j=1; j<=k; j++)
        {
            cin>>x>>t;
            build(m+i,x,t);
        }
    }
    if(m<=2000)
    {
        for(i=1; i<=q; i++)
        {
            cin>>qn[i].x>>qn[i].y;
            qn[i].num=i;
        }
        sort(qn+1, qn+q+1);
//        for(i=1; i<=q; i++) cout<<qn[i].x<<' '<<qn[i].y<<'\n';
        k=-1;
        for(i=1; i<=q; i++)
        {
            if(qn[i].x!=k)
            {
                memset(r,0,sizeof(r));
                k=qn[i].x;
                solve1(k,k,0);
            }
//            cout<<k<<' ';
            qa[qn[i].num]=r[qn[i].y]+w[qn[i].x]+w[qn[i].y];
        }
        for(i=1; i<=q; i++) cout<<qa[i]<<'\n';
    }
    /*
    for(i=1; i<=m; i++)
    {
        for(j=0; j<s[i].size(); j++)
            cout<<s[i][j].edge<<' '<<s[i][j].val<<'\n';
    }
    */
    return 0;
}
