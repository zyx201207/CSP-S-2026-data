#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i,j,k) for(register int i=j;i<=k;i++)
const int N=5e2;
const int M=2e4;
const int Q=1e5;
int n,m,k[N],ans=0,cnt=0,w[N],c,d,q,a[N][M],t[N][M],x[Q],y[Q],vis[M],dis[N][M];//dis[0]biaoshzaizhantai,dis[i]biaoshi i xianluzhanting;
vector<int> sub[M];//sub jilu i dian de xianlu sub[i][j];
void dfs(int x,int line){
    //cout<<"zhandian:"<<x<<"xianlu:"<<line<<endl;
    //if(vis[x])return;
    vis[x]=1;
    dis[line][x]=dis[0][x]+t[line][x];
    //cout<<"k[line]"<<k[line]<<endl;
    fo(i,1,k[line]){
        dis[line][a[line][i]]=min(dis[line][x],dis[line][a[line][i]]);
        //cout<<line<<" "<<a[line][i]<<" change:"<<dis[line][a[line][i]]<<endl;
        dis[0][a[line][i]]=min(dis[line][a[line][i]]+t[line][a[line][i]],dis[0][a[line][i]]);
        //cout<<0<<" "<<a[line][i]<<" change:"<<dis[0][a[line][i]]<<";"<<t[line][a[line][i]]<<":"<<t[2][2]<<endl;
        for(auto linee:sub[x])//chazhao zhegedian suoduide xianlu
        if(!vis[a[line][i]])dfs(a[line][i],sub[a[line][i]][linee]);
    }

}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    fo(i,1,m) cin>>w[i];
    fo(i,1,n){
        cin>>k[i];
        fo(j,1,k[i]){
            int cur;
            cin>>a[i][j]>>cur;
            t[i][a[i][j]]=cur;
            sub[a[i][j]].push_back(i);
        }
    }
    fo(r,1,q) cin>>x[r]>>y[r];
    /*fo(i,1,m)
    {
        cout<<"zhandian:"<<i<<"::";
        for(auto v:sub[i]) cout<<v;
        cout<<endl;
    }*/
    fo(num,1,q){
        memset(dis,0x3f3f3f3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        //cout<<x[num];
        ans=0;ans+=w[x[num]]+w[y[num]];
        //cout<<ans<<endl;
        dis[0][x[num]]=0;int ans2=0x3f3f3f3f3f3f3f;
        for(auto i:sub[x[num]]) {dfs(x[num],i);//zhandian,xiaolu;
        ans2=min(ans2,dis[0][y[num]]);
        }
        /*fo(i,1,m){
            fo(j,0,n) cout<<dis[j][i]<<" ";
            cout<<endl;
        }*/
        cout<<ans+ans2<<endl;
    }
    return 0;
}
