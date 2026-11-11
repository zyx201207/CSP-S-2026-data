#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,m,a[501010],maxn,cnt,b[501010],wz;
vector<int>v[501010];
void dfs(int f,int step){
    b[f]=step;
    if(maxn<step){
        maxn=step;
        wz=f;
    }
    for(int i=0;i<v[f].size();i++){
        if(b[v[f][i]])continue;
        dfs(v[f][i],step+1);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            v[i].clear();
        }
        for(int i=1;i<=n-1;i++){
            int u,vv;
            cin>>u>>vv;
            v[u].push_back(vv);
            v[vv].push_back(u);
        }
        if(c==7||c==11||c==12){
            wz=0,maxn=0;
            memset(b,0,sizeof b);
            dfs(1,0);
            memset(b,0,sizeof b);
            dfs(wz,0);
            if(((maxn+1)/2)%2==1&&(maxn+1)%2==1)cout<<maxn/4+1<<"\n";
            else cout<<maxn/4<<"\n";
        }
        else{
            cout<<n/(m+1)<<"\n";
        }
    }
    return 0;
    /*
0 1
6 2
 1 2
 2 3
 3 4
 4 5
 5 6
*/
}
