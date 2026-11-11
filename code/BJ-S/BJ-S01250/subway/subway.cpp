#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
/*
14:52 start

n=500?
首先考虑给每一条线路建一个虚点，可以发现这样有 O(kd) 条边，好像还可以忍受
如果我边点互换，我给线路建点，然后换乘站加边呢？
这样子，边数不超过 O(n^2)欸，点数只有O(n)，我完全可以floyd
那我询问的时候，考虑起始那个点能去哪些位置，然后终结的点从哪个地铁站出来，这样是O(d^2)的
总复杂度O(n^3+qd^2+kd)，完全可以通过，好耶
这个w数组真的是神人来的，好像啥用都没有，纯加复杂度的
开个longlong吧，有点容易炸，这个复杂度好像还不是特别的卡

15:04 start code
15:22 finish 
max point 0.74s 
*/
#define int ll
int testid,n,m,d,q;
int w[N];
int p[N][22];//每个站点经过的地铁
int t[N][22];//每个站点经过的地铁的时间
int dis[505][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    memset(dis,0x3f,sizeof dis);
    cin>>testid>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k,x,dd;
        cin>>k;
        while(k--){
            cin>>x>>dd;
            for(int j=1;j<=p[x][0];j++){
                dis[i][p[x][j]]=dis[p[x][j]][i]=min(dis[p[x][j]][i],dd+t[x][j]);
            }
            t[x][++t[x][0]]=dd;
            p[x][++p[x][0]]=i;
        }
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int ans=1e18,x,y;
        //x neq y
        cin>>x>>y;
        for(int i=1;i<=p[x][0];i++){
            for(int j=1;j<=p[y][0];j++){
                ans=min(ans,dis[p[x][i]][p[y][j]]+t[x][i]+t[y][j]);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    
    return 0;
}