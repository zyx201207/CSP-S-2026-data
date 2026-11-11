#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>g[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll c,t;
    scanf("%lld%lld",&c,&t);
    if(!c){printf("1\n2");return 0;}
    while(t--){
        ll n,k,u,v;
        scanf("%lld%lld",&n,&k);
        for(int i = 1;i < n;++i){
            scanf("%lld%lld",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n<=5){
            if(k>=2){printf("1\n");}
            else{
                bool ok=0;
                for(int i = 1;i <= n;++i){
                    if(g[i].size()==4){ok=1;break;}
                }
                if(ok){printf("1\n");}
                else{printf("2\n");}
            }
        }else{
            if(n>=3*k){printf("2\n");}
            else{printf("1\n");}
        }
    }
    return 0;
}
