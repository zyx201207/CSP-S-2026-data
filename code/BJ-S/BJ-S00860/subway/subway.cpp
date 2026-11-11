#include<bits/stdc++.h>
using namespace std;
const int N=5e5+407;
const int M=5e2+47;
const long long INF=3e18+2e17+9e16;
typedef long long ll;

ll T=1,n,m,d,q;


ll w[N];//time for going into&out_of the stations

struct line{
    ll n,t;//YES,INT
};

vector<line> l[N];

ll g[M][M];

int mian()
{
    ll C;

    /*init*/
    cin>>C>>n>>m>>d>>q;
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            g[i][j]=INF;
        }
        g[i][i]=0;
    }
    g[0][0]=INF;
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++)
    {
        ll k,tmps,tmpt;
        line tmpl;
        cin>>k;
        for(ll j=1;j<=k;j++)
        {
            cin>>tmps>>tmpt;
            //*DEL*/cout<<"succ\n"<<flush;
            tmpl.n=i;tmpl.t=tmpt;
            l[tmps].push_back(tmpl);
        }
    }
    for(ll i=1;i<=m;i++)
    {
        ll len=l[i].size();//INT MAYBE

        for(ll j=0;j<len;j++)
        {
            for(ll jj=0;jj<len;jj++)
            {
                ll lin1=l[i][j].n,lin2=l[i][jj].n;
                if(lin1!=lin2)
                {
                    //*DEL*/cout<<"aaaab ";
                    g[lin1][lin2]=min(g[lin1][lin2],(ll)(l[i][j].t+l[i][jj].t));
                }
            }
        }
        //*DEL*/cout<<"well"<<i<<"\n"<<flush;
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
    /**/
    for(ll k=1;k<=n;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            if(g[i][k]==INF or i==k)continue;
            for(ll j=1;j<=n;j++)
            {
                if(g[j][k]==INF)continue;
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
    /**/
    while(q--)
    {
        ll s,t;//INT?
        ll ans=INF;
        cin>>s>>t;
        ll lens=l[s].size(),lent=l[t].size();
        for(ll i=0;i<lens;i++)
        {
            for(ll j=0;j<lent;j++)
            {
                ans=min(ans,g[l[s][i].n][l[t][j].n]+l[s][i].t+l[t][j].t);
                //*DEL*/cout<<l[s][i].n<<l[t][j].n<<" ";
            }
        }
        ans+=w[s]+w[t];
        cout<<ans<<"\n";
    }
    //
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //cin>>T;
    while(T--)
    {
        mian();
    }
    return 0;
}

/*
======CHECK LIST========

file i/o [DONE]
long long [DONE! ALSO INF]
adjust array ranges []
calculate time [O(n^3 + m + m*d^2 + q*d^2)]
calculate space [NO IDEA! WOOOOO]
initialization [DONE - SPECIAL CHECK - BUT BETTER CHECK AGAIN LATER]
remove extra outputs [DONE]
check all warnings (Wall) [DONE]

*/
