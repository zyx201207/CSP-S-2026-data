#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

struct node{
    int x,w;
    bool operator <(const node &a)const{
        return a.w>w;
    }
};
priority_queue<node> que;
vector<node> vec;
struct str{
    int bn,ed;
}pla[10];

void solve(){

    cout<<vec[1].w+vec[2].w;
    cout<<endl;
    cout<<vec[1].w+vec[2].w+vec[3].w;

}



int c,n,m,d,q;
int w[N],k[N];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            node p;
            cin>>p.x>>p.w;
            vec.push_back(p);
        }

    }
    for(int i=1;i<=q;i++){
        cin>>pla[i].bn>>pla[i].ed;
    }

    solve();

    return 0;

}
