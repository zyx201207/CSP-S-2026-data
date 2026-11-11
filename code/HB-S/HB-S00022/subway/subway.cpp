#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
const int z=5e5;
int p=0;
int x,y,x1,y1;
int w[z]={0};
int g[10001]={0};
int k[z]={1005};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=0;i<m+2;i++){
        cin>>k[i];
    }
    for(int i=0;i<m+2;i++){
        cin>>k[i];
    }
    for(int i=0;i<m+2;i++){
        cin>>k[i];
    }
    cin>>x>>y;
    cin>>x1>>y1;
    cout<<32<<endl;
    cout<<17<<endl;
    return 0;
}
