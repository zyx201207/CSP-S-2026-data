#include<bits/stdc++.h>
#define ll long long
#define ML LONG_LONG_MAX
#define INT INT_MAX
using namespace std;
ll c,n,m,d,q;
//first bing cha ji
// `````````````````````````````````````!@#$%^&*()_+{}|:"<>?12345`67890-=[]\;',./qwertyuiopasdfghjklzxcvbnm"
int fa[3000];
void clean_fa()
{
    for(int i=0;i<=m;i++)
    {
        fa[i]=i;
    }
}
int find_fa(int i)
{
    if(fa[i]!=i)
    {
        int temp=find_fa(fa[i]);
        fa[i]=temp;
    }
    return fa[i];
}
void add_fa(int i,int j)
{
    fa[find_fa(i)]=fa[find_fa(j)];
    return;
}
bool same_fa(int i,int j)
{
    if(find_fa(i)==find_fa(j))return true;
    else return false;
}
//second map
struct node{
    ll u,v,w;
    node* next_node;
};
int point[3000];
vector<node>line;
void add_line(ll u,ll v,ll w)
{
    line.push_back({u,v,w,NULL});
    line[line.size()-1].next_node=&line[point[u]];
    point[u]=line.size()-1;
    line.push_back({v,u,w,NULL});
    line[line.size()-1].next_node=&line[point[v]];
    point[v]=line.size()-1;
    return;
}
struct node2{
    ll s;
    bool TF;
};
node2 v[3000];
ll SPFA(ll start,ll end)
{
    node* p=&line[point[start]];
    for(int i=1;i<=m;i++)
    {
        v[i].TF=false;
        v[i].s=ML;
    }
    while(1)
    {
        v[p->v].s=p->w;
        v[p->v].TF=false;
        if(p->next_node==NULL)break;
        p=p->next_node;
    }
    for(int ops=1;ops<=m;ops++)
    {
        ll min_s=ML,min_poi;
        for(ll i=0;i<m;i++)
        {
            if(v[i].s<min_s&&v[i].TF==false)
            {
                min_s=v[i].s;
                min_poi=i;
            }
        }
        v[min_poi].TF=true;
        p=&line[point[min_poi]];
        while(1)
        {
            ll temp=min_s+p->w;
            if(v[p->v].s>temp&&v[p->v].TF!=true)
            {
                v[p->v].s=temp;
            }
            if(p->next_node==NULL)break;
            p=p->next_node;
        }
    }
    return v[end].s;
}
ll asdf[3000];
ll jkl[3000][3000];
int main(){
    memset(jkl,0x3f,sizeof(jkl));
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        jkl[i][i]=0;
    }
    for(ll i=1;i<=m;i++)
    {
        scanf("%lld",&asdf[i]);
    }
    clean_fa();
    for(ll i=1;i<=n;i++)
    {
        ll ttt;
        scanf("%lld",&ttt);
        ll sb;
        ll pointhhh;
        for(int j=1;j<=ttt;j++)
        {
            scanf("%lld",&pointhhh);
            if(j==1)sb=pointhhh;
            add_fa(pointhhh,sb);
            ll uiiu;
            scanf("%lld",&uiiu);
            jkl[find_fa(pointhhh)][pointhhh]=uiiu;
        }
        ll cn=find_fa(pointhhh);
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=m;k++)
            {
                add_line(j,k,jkl[cn][j]+jkl[cn][k]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        ll begin,end;
        scanf("%lld %lld",&begin,&end);
        printf("%lld\n",SPFA(begin,end));
    }
    return 0;
}










 //bing cha ji ce shi
    /*
    int n,m;
    cout<<"in the mensum    in the line sum"<<'\n';
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add_fa(a,b);
    }
    cout<<'\n';
    cout<<"in the check num:a,b"<<'\n';
    int y;
    cin>>y;
    for(int i=1;i<=y;i++)
    {
        int a,b;
        cin>>a>>b;
        if(same_fa(a,b))cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    */