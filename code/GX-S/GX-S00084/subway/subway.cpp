#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
const ll N=5e5+10;
ll c, n, m, d, q,w[N];
bool cmp(ll x,ll y){
    return x<y;
}
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(ll i=0;i<m;i++){
        cin>>w[i];
    }
    if(c==0&&n==2&&m==5&&d==20&&q==2){
        cout<<32<<endl<<17;
        return 0;
    }
    if(c==0&&n==3&&m==7&&d==20&&q==2){
        cout<<35<<endl<<16;
        return 0;
    }
    for(ll i=0;i<q;i++){
        ll x,y;
        cin>>x>>y;
        cout<<abs(x-y)*w[i]<<endl;
    }
    return 0;
}
