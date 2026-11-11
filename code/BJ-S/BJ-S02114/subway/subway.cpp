#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 505;
struct xl{
   int tt;
   bool b = false;
};
struct sta{
    xl xianlu[205];
}stat[405];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,d,q,k;
    cin>>c>>n>>m>>d>>q;
    ll w[405];
    for(ll i = 1;i <= m;i++){
        cin>>w[i];
    }
    for(int i = 1;i <= n;i++){
        int k;
        cin>>k;
        for(int j = 1;j <= k;j++){
            int a,t;
            cin>>a>>t;
            stat[a].xianlu[i].tt = t;
            stat[a].xianlu[i].b = true;
        }
    }
    while(q--){
        int s,e,xxll = 0;
        bool bq = false;
        cin>>s>>e;
        for(int i = 1;i <= n;i++){
            if(stat[s].xianlu[i].b == true && stat[e].xianlu[i].b == true){\
                bq = true,xxll = i;
                break;
            }
        }
        if(bq == true){
            cout<<w[s] + w[e] + stat[s].xianlu[xxll].b + stat[e].xianlu[xxll].b<<endl;
        }
    }
    return 0;
}
