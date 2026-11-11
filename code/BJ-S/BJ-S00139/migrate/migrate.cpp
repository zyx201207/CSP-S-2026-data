#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int n,d,x[N];
struct node{
    int id,num;
    bool operator < (const node& other) const{
        return num > other.num;
    }
};
bool check(int u,int v){
    int cnt=0,p=0,tmp=u;
    for(int i=u;i<=v;i++){
        if(x[i] - x[tmp] > d){
            if(x[tmp+1]-x[tmp] > d)return false;
            tmp=i-1;
            p++;
        }
    }
    priority_queue<node> q;
    q.push({u,0});
    while(!q.empty()){
        node y=q.top();
        q.pop();
        if(y.id == v){
            cnt++;
            continue;
        }
        if(y.num > p)continue;
        for(int lo=y.id+1;lo<=n &&x[lo]-x[y.id] <= d;lo++){
            q.push({lo,y.num+1});
        }
    }
    return cnt == 2;
}
void solve(){
    scanf("%d %d",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    long long ans=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(check(i,j))ans++;
        }
    }
    printf("%lld\n",ans);
}
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d %d",&c,&t);
    while(t--){
        solve();
    }

    return 0;
}
