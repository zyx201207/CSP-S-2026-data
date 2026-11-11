#include<bits/stdc++.h>
using namespace std;
struct node{
   int a;
   int t;
};
struct xandy{
   int x;
   int y;
};


void solve(){
    int n,m,d,q;
    cin>>n>>m>>d>>q;
    vector<int> w(m);
    for(int i=0;i<n;i++) cin>>w[i];
    vector<node> aandt(n);
    vector<int> k(n);
    for(int i=0;i<n;i++){
            cin>>k[i];
        for(int i=0;i<k[i];i++){
            cin>>aandt[i].a>>aandt[i].t;
        }
    }
    vector<xandy> dream(q);
    for(int i=0;i<q;i++) cin>>dream[i].x>>dream[i].y;
    int ans=0;
    int answ=0;
    for(int i=0;i<n;i++){
        answ+=w[sad[q].x]+w[sad[q].y];
    }
    int ansz=0;
    for(int i=0;i<q;i++){
        ansz=aandt[sad[q].x].a+aandt[sad[q].y].t+aandt[sad[q].x+1].a+aandt[sad[q].y+1].t;
    }
    ans=answ+ansz;
    cout<<ans<<'\n';
}


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin>>c;
    while(c--){
        solve();
    }

    return 0;
}
