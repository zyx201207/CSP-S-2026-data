#include<bits/stdc++.h>
using namespace std;
//#define WZH_LOCAL
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define foR(i,a,b) for(int i=(a);i>=(b);i--)
int t=1;
const int N=505;
const int M=2e3;
int c,m,n,d,q;
int cnt;
int w[N];
int dis[N+M][N+M];
struct node{
    int fa,val,pt;
}line[M][N];
vector<int>v[N+M];
signed main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    #ifndef WZH_LOCAL
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    #endif // WZH_LOCAL
    //cin>>t;
    while(t--){
        cin>>c>>m>>n>>d>>q;
        cnt=n;
        if(c<=6){
            //Floyd
            For(i,1,n) cin>>w[i];
            For(i,1,m){
                cin>>line[i][0].fa;
                For(j,1,line[i][0].fa){
                    int _a,_v;
                    cin>>_a>>_v;
                    line[i][j]={_a,_v,++cnt};
                }
            }
            For(i,1,cnt)
                For(j,1,cnt)
                    if(i!=j)
                        dis[i][j]=LLONG_MAX/3;
            For(i,1,m)
                For(j,1,line[i][0].fa){
                    auto [_fa,_val,_pt]=line[i][j];
                    // cout<<i<<' '<<_fa<<' '<<_val<<' '<<_pt<<'\n';
                    dis[_fa][_pt]=dis[_pt][_fa]=_val;
                    For(k,j+1,line[i][0].fa)
                        dis[_pt][line[i][k].pt]=dis[line[i][k].pt][_pt]=0;
                }
            // cout<<"cnt:"<<cnt<<'\n';
            // cout<<"start:\n";
            // For(i,1,cnt){
            //     cout<<"point "<<i<<'\n';
            //     For(j,1,cnt)
            //         if(dis[i][j]!=LLONG_MAX/3) cout<<dis[i][j]<<' ';
            //         else cout<<"L ";
            //     cout<<'\n';
            // }
            //Floyd Time
            For(k,1,cnt)
                For(i,1,cnt)
                    For(j,i+1,cnt)
                        if(i!=j&&j!=k&&k!=i)
                            dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
            // cout<<"end:\n";
            // For(i,1,cnt){
            //     cout<<"point "<<i<<'\n';
            //     For(j,1,cnt)
            //         if(dis[i][j]!=LLONG_MAX/3) cout<<dis[i][j]<<' ';
            //         else cout<<"L ";
            //     cout<<'\n';
            // }
            while(q--){
                int pos1,pos2;
                cin>>pos1>>pos2;
                cout<<w[pos1]+w[pos2]+dis[min(pos1,pos2)][max(pos1,pos2)]<<'\n';
            }
        }
        else{
            For(i,1,n) cin>>w[i];
            For(i,1,n)
                For(j,1,n)
                    dis[i][j]=LLONG_MAX/3;
            For(i,1,m){
                int k;
                cin>>k;
                if(k==1) cin>>k>>k;
                else{
                    int pos1,dis1,pos2,dis2;
                    cin>>pos1>>dis1>>pos2>>dis2;
                    dis[pos1][pos2]=min(dis[pos1][pos2],dis1+dis2);
                    dis[pos2][pos1]=min(dis[pos2][pos1],dis2+dis1);
                }
            }
            For(k,1,n)
                For(i,1,n)
                    For(j,i+1,n)
                        if(i!=j&&j!=k&&k!=i)
                            dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
            while(q--){
                int pos1,pos2;
                cin>>pos1>>pos2;
                cout<<w[pos1]+w[pos2]+dis[min(pos1,pos2)][max(pos1,pos2)]<<'\n';
            }
        }
    }
    return 0;
}
