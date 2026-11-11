#include<bits/stdc++.h>
#define maxn 500050

using namespace std;
typedef long long ll;

struct edge
{
    int v,id;
};

struct node
{
    int v,id,tim;
};

ll read()
{
    ll res=0;
    ll tmp=1;
    char ch=getchar();
    while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
    if(ch=='-') tmp=-1,ch=getchar();
    while(ch>='0'&&ch<='9') res=res*10+ch-'0',ch=getchar();
    return res*tmp;
}

int c,d,q,n,m;
vector<edge> e[maxn];
int w[maxn];
int t[10][15];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        int lst;
        for(int j=1;j<=k;j++)
        {
            int a,b;
            cin>>a>>b;
            if(j==1)
            {
                t[i][j]=b;
                lst=a;
            }
            else 
            {
                e[a].push_back({lst,i});
                e[lst].push_back({a,i});
                t[i][j]=b;
                lst=a;
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]<<'\n';
    }
    return 0;
}