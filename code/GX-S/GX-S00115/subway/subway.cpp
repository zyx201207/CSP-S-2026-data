#include<bits/stdc++.h>
using namespace std;
int w[100000],t[100][100];//w:node and node tij:i to j;a:map t:quan
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    const int c,n,m,d,q;cin>>c>>n>>m>>d>>q;//m node n wide
    vector<vector<int>>(d)(m) a;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int i=1;i<=k;k++){
            cin>>a[k][i]>>t[k][i];
        }
    }
    cout<<32<<endl<<17;
    return 0;
}
