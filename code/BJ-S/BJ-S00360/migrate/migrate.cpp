#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d;
int a[N];
vector<int> v[N];
struct node{
    int x,dis;
};
int bfs(int x,int y){
    int ans=0,num=0;
    queue<node> q;
    q.push({x,0});
    while(!q.empty()){
        node now=q.front();
        q.pop();
        if(now.dis>n) break;
        if(now.x==y){
            if(num!=0&&now.dis!=num){
                break;
            }
            num=now.dis;
            ans++;
            continue;
        }
        for(auto it:v[now.x]){
            q.push({it,now.dis+1});
        }
    }
    return ans;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            v[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(a[j]-a[i])<=d){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int num=bfs(i,j);
                if(num==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
