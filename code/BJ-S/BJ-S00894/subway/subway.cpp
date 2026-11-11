#include<bits/stdc++.h>
using namespace std;
struct node {
    long long to,len;
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    long long t[500005]={0};
    for(int i=1;i<=m;i++){
        cin>>t[i];
    }
    if(c==20||c==21){
        long long k;
        int sub[500005]={0};
        long long g[2][2]={{0,INT_MAX},{INT_MAX,0}};
        cin>>k;
        for(int j=0;j<k;j++){
            long long x,y;
            cin>>x>>y;
            sub[x]=y;
        }
        cin>>k;
        long long ans=INT_MAX;
        for(int i=0;i<k;i++){
            long long x,y;
            cin>>x>>y;
            g[0][1]=min(g[0][1],sub[x]+y);
            g[1][0]=g[0][1];
        }
        for(int i=0;i<q;i++){
            int s,e;
            cin>>s>>e;
            if((sub[s]&&sub[e])||(sub[s]==0&&!sub[e]==0)){
                cout<<t[s]+t[e]<<'\n';
            }else{
                cout<<t[s]+t[e]+g[1][0]<<'\n';
            }
        }
        return 0;
    }
    vector<node> sub[90005];
    long long g[505][505];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]=INT_MAX;
        }
    }
    for(int i=1;i<=n;i++){
        long long k;
        cin>>k;
        for(int j=0;j<k;j++){
            long long x,y;
            cin>>x>>y;
            sub[x].push_back({i,y});
            for(node wh:sub[x]){
                g[i][wh.to]=min(y+wh.len,g[i][wh.to]);
                g[wh.to][i]=min(y+wh.len,g[i][wh.to]);
            }
        }
        g[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<k;i++){
            for(int j=k;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                g[j][i]=g[i][j];
            }
        }
    }
    for(int i=0;i<q;i++){
        int s,e;
        cin>>s>>e;
        long long ans=INT_MAX;
        for(node wh:sub[s]){
            for(node hw:sub[e]){
                ans=min(g[wh.to][hw.to]+wh.len+hw.len,ans);
                //cout<<ans<<'\n';
            }
        }
        ans+=t[s]+t[e];
        cout<<ans<<'\n';
    }
    return 0;
}