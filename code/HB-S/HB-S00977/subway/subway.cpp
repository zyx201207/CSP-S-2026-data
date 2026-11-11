#include <bits/stdc++.h>
using namespace std;

struct subway{
    int a, t;
};

int c, n, m, d, q, w[500001];
vector<subway> s[501];

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;i<=k;j++){
            subway x;
            cin>>x.a>>x.t;
            s[i].push_back(x);
        }
    }
    for(int i=1;i<=q;i++){
        int x, y;
        cin>>x>>y;
        int ans;
        cout<<ans<<endl;
    }
    return 0;
}
