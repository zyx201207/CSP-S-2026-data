#include<bits/stdc++.h>
using namespace std;
const int M=250005;
int c,n,m,d,q,k[M];
int w[M],a[M][50],t[M][50],tong[M];
bool vis[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[j][i]>>t[j][i];
            tong[a[j][i]]++;
        }
    }
    for(int i=1;i<=q;i++){
        int o,p,ans=0,biao=0;
        cin>>o>>p;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[j][i]==o){
                    vis[o]=i;
                }else if(a[j][i]==p){
                    vis[p]=i;
                }
            }
            if(tong[i]>=2){
                biao=i;
            }
        }
        if(vis[o]!=vis[p]){
            ans+=a[biao][1];
            ans+=a[biao][2];
        }
        ans+=w[o]+t[o][vis[o]]+w[p]+t[p][vis[p]];
        cout<<ans<<endl;
    }
    return 0;
}
