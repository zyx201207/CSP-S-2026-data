#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6+10;
LL c,n,m,d,q,w[N];
int h[510][510],h1[N],h2[N],op;
vector<int> ji[100];
int main(){
    std::ios::sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>w[i];
    }
    for(int i = 1;i<=n;i++){
        if(i == 1){
            int k;
            cin>>k;
            for(int j = 1;j<=k;j++){
                int x,y;
                cin>>x>>y;
                h1[x] = y;
            }
        }
        else{
            int k;
            cin>>k;
            for(int j = 1;j<=k;j++){
                int x,y;
                cin>>x>>y;
                h2[x] = y;
            }
        }
    }
    for(int i = 1;i<=N;i++){
        if(h1[i]&&h2[i]) op = i;
    }
    while(q--){
        int ans = 0;
        int a,b;
        cin>>a>>b;
        ans+=w[a];
        if(h1[a]&&h1[b]){
            ans+=h1[a];
            ans+=h1[b];
        }
        else if(h2[a]&&h2[b]){
            ans+=h2[a];
            ans+=h2[b];
        }
        else if(h1[a]&&h2[b]){
            ans+=h1[a];
            ans+=h1[op]+h2[op];
            ans+=h2[b];
        }
        else{
            ans+=h2[a];
            ans+=h2[op]+h1[op];
            ans+=h1[b];
        }
        ans+=w[b];
        cout<<ans<<endl;
    }
    return 0;
}
