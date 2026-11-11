#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<cstdio>
typedef long long ll;
using namespace std;
vector<pair<int,int> > zt[500005];
ll dis[505][505];
int w[500005],k[505];
int read(){
    int x=0,c=1;
    char ch;
    ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            c=-1;
        }
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar_unlocked();
    }
    return x*c;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    c=read();n=read();m=read();d=read();q=read();
    //cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        w[i]=read();
        //cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        k[i]=read();
        //cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int aa,tt;
            aa=read();tt=read();
            //cin>>aa>>tt;
            zt[aa].push_back(make_pair(i,tt));
            //a[i].push_back(aa);
            //t[i].push_back(tt);
            //zt[aa].push_back()
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        for(auto j:zt[i]){
            for(auto k:zt[i]){
                if(k==j){
                    continue;
                }
                //cout<<j.first<<" "<<k.first<<endl;
                dis[j.first][k.first]=min(dis[j.first][k.first],ll(j.second)+ll(k.second));
                dis[k.first][j.first]=dis[j.first][k.first];
            }
        }
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
    while(q--){
        int x,y;
        x=read();y=read();
        //cin>>x>>y;
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(auto i:zt[x]){
            for(auto j:zt[y]){
                if(i.first==j.first){
                    ans=min(ans,ll(i.second)+(j.second));
                    continue;
                }
                ans=min(ans,dis[i.first][j.first]+i.second+j.second);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
        //cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
