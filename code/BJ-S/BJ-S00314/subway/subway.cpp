#include<bits/stdc++.h>
using namespace std;
int w[500005],t[505][500005];
vector<int> a[500005];
struct line{
    int a,b=-1,ta,tb;
}l[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int id;
        cin>>id;
        cin>>t[i][id];
        a[id].push_back(i);
        l[i].a=id;
        l[i].ta=t[i][id];
        if(k==2){
            cin>>id;
            cin>>t[i][id];
            a[id].push_back(i);
            l[i].b=id;
            l[i].tb=t[i][id];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=w[x]+w[y];
        int op=x;
        while(!a[op].empty()){
            for(int u:a[op]){
                ans+=t[x][op]+t[u][op];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
