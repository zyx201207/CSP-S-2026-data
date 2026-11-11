#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
const int M=505;
int w[N];
int c,n,m,d,q,cnt;
int f[M][M];
struct L{
    int ti;
    int b;
};
vector<L> jg[N];

void Floyd(){
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    cnt=m;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    memset(f,0x3f,sizeof(f));
    //cout<<f[1][1]<<'\n';
    for(int i=1;i<=n;i++){
        int x,last;
        cin>>x;
        for(int j=1;j<=x;j++){
            int v,t;
            cin>>v>>t;
            
            int l=jg[v].size();
            if(l!=0){
                for(auto p:jg[v]){
                    int ti=p.ti;
                    int b=p.b;
                    //if(b==i) f[i][b]=f[b][i]=0;
                    f[b][i]=f[i][b]=min(f[i][b],ti+t);
                }
            }
            jg[v].push_back({t,i});
        }

    }
    //cout<<cnt<<'\n';
    // for(int i=1;i<=m;i++,cout<<'\n')
    //     for(auto p:jg[i])
    //         cout<<p.first<<' ';
    Floyd();
    //cout<<f[1][1]<<'\n';
    for(int i=1;i<=q;i++){
        int st,se,ans=1e18;
        cin>>st>>se;
        for(auto x:jg[st]){
            for(auto y:jg[se]){
                ans=min(ans,f[x.b][y.b]+x.ti+y.ti);
                //cout<<x.b<<' '<<y.b<<' '<<f[x.b][y.b]<<'\n';
            }
                
        }
        cout<<ans+w[st]+w[se]<<'\n';
    }

    return 0;
}