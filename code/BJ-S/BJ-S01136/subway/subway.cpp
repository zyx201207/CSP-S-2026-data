#include<bits/stdc++.h>
#define _for(i,x,y) for(int i=x;i<=y;++i)
#define _rep(i,x,y) for(int i=x;i<y;++i)
#define _forp(i,x,y,z) for(int i=x;i<=y;i+=z)
using namespace std;
#define int long long
const int N=505,M=500005;
int C,n,m,d,q;
int f[N][N],w[M];
struct node{
    int num,tim;
};
vector<node> cross[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>C>>n>>m>>d>>q;
    _for(i,1,m) cin>>w[i];
    _for(i,1,n){
        int ki; cin>>ki;
        _for(j,1,ki){
            int A,T; cin>>A>>T;
            cross[A].push_back({i,T});
        }
    }
    memset(f,0x3f,sizeof f);
    _for(i,1,n) f[i][i]=0;
    _for(pos,1,m){
        int sz=cross[pos].size();
        _for(j,0,sz-1){
            _for(k,j+1,sz-1){
                int U=cross[pos][j].num;
                int V=cross[pos][k].num;
                int W=cross[pos][j].tim+cross[pos][k].tim;
                f[U][V]=f[V][U]=min(f[U][V],W);
            }
        }
    }
    //build f
    _for(k,1,n){
        _for(i,1,n){
            _for(j,1,n){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    /*_for(i,1,n){
        cout<<"position = "<<i<<'\n';
        for(auto j:cross[i]){
            cout<<j.num<<' '<<j.tim<<'\n';
        }
        cout<<'\n';
    }*/
    while(q--){
        int xr,yr;
        cin>>xr>>yr;
        int ans=f[0][0];
        for(auto i:cross[xr]){
            for(auto j:cross[yr]){
                int U=i.num;
                int V=j.num;
                int W=w[xr]+w[yr]+i.tim+j.tim+f[U][V];
                //cout<<U<<','<<V<<':'<<i.tim+j.tim<<'\n';
                ans=min(ans,W);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
