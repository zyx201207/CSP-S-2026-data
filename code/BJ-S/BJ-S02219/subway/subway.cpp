#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+5,M=5e5+5;
ll mp[N][N];
ll f[N][N];
int w[M];
struct node{
    ll x;
    ll y;
};
vector<node>a[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            a[i].push_back({x,y});
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            mp[i][j]=1E18;
        }
        mp[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size();j++){
            for(int k=0;k<a[i].size();k++){
                if(j==k)continue;
                mp[a[i][j].x][a[i][k].x]=min(mp[a[i][j].x][a[i][k].x],a[i][j].y+a[i][k].y);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
            }
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<(ll)((ll)(mp[x][y]+w[x])+w[y])<<"\n";
    }
    return 0;
}
