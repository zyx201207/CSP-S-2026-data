#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int n,d,ans,cnt[maxn],dis[maxn],a[maxn];
vector<int> v[maxn];
void add(int x,int y){
    v[x].push_back(y);
    v[y].push_back(x);
}
void bfs(int st){
    queue<pair<int,int> > q;
    pair<int,int> pp;
    pp.first=st;
    pp.second=0;
    q.push(pp);
    for(int i=1;i<=n;i++){
        cnt[i]=0;
        dis[i]=1e9;
    }
    cnt[st]=1;
    dis[st]=0;
    while(!q.empty()){
        int x=q.front().first,s=q.front().second;
        q.pop();
        if(s>dis[x]){
            continue;
        }
        for(int i=0;i<v[x].size();i++){
            int dx=v[x][i];
            if(dis[dx]>dis[x]+1){
                dis[dx]=dis[x]+1;
                cnt[dx]=cnt[x];
                pair<int,int> pp;
                pp.first=dx;
                pp.second=s+1;
                q.push(pp);
            }
            else if(dis[dx]==dis[x]+1){
                cnt[dx]+=cnt[x];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]==2){
            ans++;
        }
    }
}
signed main(){
    int c,t;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int cha;
        bool flag=true;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            v[i].clear();
            if(i==2){
                cha=a[i]-a[i-1];
            }
            else if(i>2){
                if(a[i]-a[i-1]!=cha){
                    flag=false;
                }
            }
        }
        if(!flag){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(abs(a[i]-a[j])<=d){
                        add(i,j);
                    }
                }
            }
            ans=0;
            for(int i=1;i<=n;i++){
                bfs(i);
            }
            cout<<ans/2<<'\n';
        }
        else{
            int d2=d/cha;
            if(n-2*d2+1<0||d2<=1){
                cout<<0<<'\n';
            }
            else{
                cout<<n-2*d2+1<<'\n';
            }

        }
    }
    return 0;
}
