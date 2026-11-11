#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=2e6+10;
ll c,t,a[N];//第1个大于a[i]的下标 没有是0

struct Node{
    ll w;
};
vector<Node> xb[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ll n,d;
        scanf("%lld%lld",&n,&d);
        memset(a,0,sizeof a);
        memset(xb,0,sizeof xb);
        for(register int i=1; i<=n;i++){
            scanf("%lld",&a[i]);
        }
        queue<int> q;
        for(register int i=1; i<=n;i++){
            if(q.empty()) q.push(i);
            else{
                while(a[i]>a[q.front()]+d&&!q.empty()){
                    xb[q.front()].push_back({i});
                    q.pop();
                }
                q.push(i);
            }
        }
        ll ans=0;
        for(register int i=1; i<=n;i++){
                for(register int j=0; j<xb[i].size();j++){
                    if(xb[i][j].w!=0){
                        ll x=xb[i][j].w-i-1;
                        ll y=a[xb[i][j].w]-a[i];
                        if(x==2&&y<=d*2) {
                            ans++;
                        }
                    }
                }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
