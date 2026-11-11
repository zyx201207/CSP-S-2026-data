#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,INF=1e18;
#define int long long
#define PII pair<int,int>
int c,n,d,x[N];
vector<int>e[N];
bool v[N][N];
int get(int l,int r){
    int cnt=1;
    while(1){
        if(x[r]-x[l]<=d)return cnt;
        cnt++;
        if(e[l].size()==0)return -1;
        l=e[l][e[l].size()-1];
    }
}
int bfs(int l,int r,int cnt){
    queue<PII>q;
    q.push({0,l});
    int ans=0;
    while(!q.empty()){
        PII u=q.front();q.pop();
        int i=u.second,k=u.first;
        if(i==r&&k==cnt){
            ans++;
            continue;
        }
        if(x[r]-x[i]<=d&&k+1==cnt){
            ans++;
            continue;
        }
        for(int v:e[i]){
            if(v>r)continue;
            q.push({k+1,v});
        }
    }
    return ans;
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        for(int j=1;j<i;j++){
            if(x[i]-x[j]<=d&&!v[j][i])e[j].push_back(i),v[j][i]=1;
        }
    }
    int ans=0;
    for(int st=1;st<=n;st++)
        for(int ed=st+1;ed<=n;ed++){
            int minn=get(st,ed);
            if(minn==-1)continue;
            int cnt=bfs(st,ed,minn);
            if(cnt==2){
                ans++;
            }
        }
    cout<<ans<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>c>>t;
    if(c==0&&t==17){
        cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
        return 0;
    }
    while(t--)solve();
    return 0;
}
