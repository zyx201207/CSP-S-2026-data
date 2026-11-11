#include <iostream>
using namespace std;
struct Point{
    int lined[40],w,a,t[40];
}subway[500050];
typedef long long ll;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>subway[i].w;
    for(int i=1;i<=n;++i){
        int k;cin>>k;
        for(int j=1;j<=k;++j){
            int a,t;cin>>a>>t;
        }
    }
    return 0;
}
