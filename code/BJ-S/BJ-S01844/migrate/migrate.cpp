
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+9;
struct node{
    int x,i;
};
int C,T,n,ans;
node v[N];
ll d,a[N];
vector<int> p[N];
queue<node> q;
void bfs(int x){
    for(int i=1;i<=n;i++)v[i].x=0,v[i].i=0;
    for(auto v:p[x])q.push({v,1});
    while(!q.empty()){
        node t=q.front();q.pop();
        if(v[t.x].i==0||v[t.x].i==t.i)v[t.x].x++,v[t.x].i=t.i;
        for(auto v:p[t.x])q.push({v,t.i+1});
    }
    for(int i=1;i<=n;i++){
        if(v[i].x==2){
            ans++;
            // cout<<x<<' '<<i<<endl;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)while(!p[i].empty())p[i].pop_back(); 
        while(!q.empty())q.pop();
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]>d)break;
                p[i].push_back(j);
            }
        }
        for(int i=1;i<=n;i++)bfs(i);
        cout<<ans<<endl;
    }
    return 0;
}