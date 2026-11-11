#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000005];
int h[1000005];
void dfs(int x,int y,int z){
    h[x]=z;
    for (int i=0;i<v[x].size();i++){
        if (v[x][i]!=y) dfs(v[x][i],x,z+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if (c<=12){
        while(t--){
            int n,k;
            cin>>n>>k;
            int a,b;
            for (int i=1;i<=n-1;i++){
                cin>>a>>b;
                v[a].push_back(b);
                v[b].push_back(a);
            }
            dfs(1,0,0);
            int maxn=-1,ji;
            for (int i=1;i<=n;i++){
                if (h[i]>maxn){
                    maxn=h[i];
                    ji=i;
                }
                h[i]=0;
            }
            dfs(ji,0,0);
            maxn=-1;
            for (int i=1;i<=n;i++){
                if (h[i]>maxn){
                    maxn=h[i];
                    ji=i;
                }
            }
            if (k<=2) cout<<h[ji]/(k+1)<<endl;
            else if (k>=3){
                if (k!=n) cout<<1<<endl;
                else cout<<0<<endl;
            }
            for (int i=1;i<=n;i++) v[i].clear();
        }
    }
    return 0;
}