#include<bits/stdc++.h>
using namespace std;
long long w[500010];
long long sz1[500010],sz2[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        long long zs;
        cin>>zs;
        for(int j=1;j<=zs;j++){
            cin>>u>>v;
            if(i==1){
                sz1[u]=v;
            }else if(i==2){
                sz2[u]=v;
            }
        }
    }
    long long mid=1e17;
    for(int i=1;i<=m;i++){
        if(sz1[i]!=0&&sz2[i]!=0){
            mid=min(mid,sz1[i]+sz2[i]);
        }
    }
    for(int i=1;i<=q;i++){
        int r,s;
        cin>>r>>s;
        cout<<w[r]+w[s]+mid<<"\n";
    }
    return 0;
}