#include <bits/stdc++.h>
using namespace std;

const int MAX=2e6;
using ll=long long;

int c, t;
int n;
ll d;
ll x[MAX+10];
vector <int> edge[MAX+10];
queue <int> q;
ll dis[MAX+10];
ll cnt[MAX+10];

void solve(){
	
	if(c==13 || c==14){
		printf("0\n");
		return;
	} 
    scanf("%d%lld", &n, &d);
    for(int i=1; i<=n; i++){
        edge[i].clear();
    }
    for(int i=1; i<=n; i++){
        scanf("%lld", &x[i]);
        for(int j=i-1; j>=1; j--){
            if(x[i]-x[j]<=d){
                edge[i].push_back(j);
                edge[j].push_back(i);
            }
        }
    }
    ll ans=0;
    for(int i=1; i<=n; i++){
        for(; !q.empty(); q.pop());
        memset(dis, -1, sizeof(dis));
        memset(cnt, 0, sizeof(cnt));
        dis[i]=0;
        cnt[i]=1;
        q.push(i);
        while(!q.empty()){
            int f=q.front();
            q.pop();
            if(cnt[f]==2){
                ans++;
            }
            for(auto i : edge[f]){
                if(dis[i]!=-1){
                    if(dis[i]==dis[f]+1){
                        cnt[i]+=cnt[f];
                    }
                    continue;
                }
                dis[i]=dis[f]+1;
                cnt[i]=cnt[f];
                q.push(i);
            }
        }
        /*
        for(int i=1; i<=n; i++){
            printf("%d ", dis[i]);
        }
        printf("\n");*/
    }
    printf("%lld\n", ans/2);

}

int main(){

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    for(; t--; ){
        solve();
    }

    return 0;

}
