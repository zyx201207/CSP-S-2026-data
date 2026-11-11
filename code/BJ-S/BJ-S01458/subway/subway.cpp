#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long

using namespace std;

const int N=5e5+10;

int c,n,m,d,q;
int up[N],t[N];

signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(n!=1) return 0;
    for(int i=1;i<=m;i++) cin>>up[i];
    for(int i=1;i<=m;i++) {
        int a;
        cin>>a;
        cin>>t[a];
    }
    while(q--) {
        int x,y;
        cout<<up[x]+up[y]+t[x]+t[y]<<"\n";
    }
    return 0;
}