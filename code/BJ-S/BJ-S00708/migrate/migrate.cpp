#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll read(){
    ll igt=0,sgn=1;
    char c=getchar();
    while(c<'0' or c>'9'){
        if(c=='-'){
            sgn=-1;
        }
        c=getchar();
    }
    while(c<='9' and c>='0'){
        igt=(igt<<3)+(igt<<1)+c-'0';
        c=getchar();
    }
    return igt*sgn;
}

const ll maxn=int(2e6+5);

ll pos[maxn];
ll dp[maxn];

ll dis[maxn],cnt[maxn];

queue <int> q;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ll c=read(),t=read();
    if(c>=0 and c<=10){
        while(t--){
            ll n=read(),d=read();
            for(ll i=1;i<=n;i++){
                pos[i]=read();
            }
            ll ans=0;
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++){
                    dis[j]=0x3f3f3f3f3f3f3f3f;
                    cnt[j]=0;
                }
                while(!q.empty()){
                    q.pop();
                }
                q.push(i);
                dis[i]=0;
                while(!q.empty()){
                    ll tmp=q.front();
                    q.pop();
                    for(ll j=tmp+1;j<=n and pos[j]-pos[tmp]<=d;j++){
                        if(dis[j]>dis[tmp]+1){
                            dis[j]=dis[tmp]+1;
                            cnt[j]=1;
                            q.push(j);
                        }
                        else if(dis[j]==dis[tmp]+1){
                            cnt[j]++;
                            q.push(j);
                        }
                        else{

                        }
                    }
                }
                for(ll j=i+1;j<=n;j++){
                    ans+=(cnt[j]==2);
                }
            }
            printf("%lld\n",ans);
        }
    }
    else{
        while(t--){
            cout<<"0\n";
        }
    }
    return 0;
}
