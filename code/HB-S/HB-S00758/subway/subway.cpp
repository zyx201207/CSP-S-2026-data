#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int c,n,m,d,q;
int w[N],k[N];
vector<int> route[N],t[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,a,tt;j<=k[i];j++){
            cin>>a>>tt;
            route[i].push_back(a);
            t[i].push_back(tt);
        }
    }
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        cout<<w[x]+w[y];
    }
    return 0;
}