#include<bits/stdc++.h>
using namespace std;
struct node{
    int next;
    int val;
};
int c,n,m,d,q;
long long  go[500005];
vector<node> v[1005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1;i<=m;i++){
        scanf("%lld",&go[i]);
    }
    for(int i =1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j = 1;j<=k;j++){
            int a,t;
            scanf("%d%d",&a,&t);
            v[i*2-1].push_back({a*2,t});
            v[a*2].push_back({i*2-1,t});
        }
    }
    while(q--){
        long long vis[1005]={0};
        int x,y;
        scanf("%d%d",&x,&y);
        queue<int> q;
        q.push(x*2);
        while(!q.empty()){
            int temp=q.front();q.pop();
            for(node i : v[temp]){
                if(vis[i.next]>vis[temp]+i.val or vis[i.next]==0){
                    vis[i.next]=vis[temp]+i.val;
                    q.push(i.next);
                }
            }
        }
        printf("%lld\n",vis[y*2]+go[x]+go[y]);
    }
}
