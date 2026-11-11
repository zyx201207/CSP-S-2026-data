#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pai;
const int N=550;
const int M=5e5+50;
ll dis[N][N];
vector<pai>v[2*M];//站台及其路径长度
int c,n,m,d,q;
int w[M];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int len;
        cin>>len;
        while(len--){
            int a,t;
            cin>>a>>t;
            //if(a==1)cout<<"DD\n";
            v[a+n].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=n+1;i<=n+m;i++){
        for(int j=0;j<v[i].size();j++){
            for(int k=0;k<j;k++){
                int d1=v[i][j].first,d2=v[i][k].first;
                ll t1=v[i][j].second,t2=v[i][k].second;
                //if(i-n==3)cout<<d1<<" "<<d2<<" "<<t1<<" "<<t2<<"\n";
                //if(i-n==2)cout<<d1<<" "<<d2<<" "<<t1<<" "<<t2<<"\n";
                dis[d1][d2]=min(dis[d1][d2],t1+t2);
                dis[d2][d1]=min(dis[d2][d1],t1+t2);
            }
        }
    }
    floyd();
    //cout<<dis[1][3]<<"\n";
    while(q--){
        int bg,ed;
        cin>>bg>>ed;
        ll ans=1e18;
        for(auto i:v[bg+n]){
            for(auto j:v[ed+n]){
                int d1=i.first,d2=j.first;
                ll t1=i.second,t2=j.second;
                if(t1+t2+dis[d1][d2]==8){
                    //cout<<"EDGE:"<<d1<<" "<<d2<<" "<<t1<<" "<<t2<<"\n";
                }
                ans=min(ans,t1+t2+dis[d1][d2]);
            }
        }
        cout<<ans+w[bg]+w[ed]<<"\n";
    }
    return 0;
}
