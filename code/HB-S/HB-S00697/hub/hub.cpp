#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=505;

int c,n,m,d,q;
struct f{
    int a;
    int t;
    int id;
};
vector<f> g[N];
int kouting[N];
//t:zhanting->zhantai     kouting[i]:ditiekou->zhanting
//bian: pos
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>kouting[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int t,a;
            cin>>a>>t;
            g[i].push_back({a,t,j});
            g[a].push_back({i,t,j});
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=0;
        for(f u:g[x]){
            ans+=kouting[u.id];
            ans+=u.t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
