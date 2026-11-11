#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int c[100001];
vector<int>a[100001];
int dis[100001],cnt[100001];
struct p{
    int x,y;
};
void slove(int st){
    for(int i=0;i<n;i++){
        dis[i]=99999999;
        cnt[i]=0;
    }
    queue<p>q;
    q.push({st,0});
    while(!q.empty()){
        int u=q.front().x,d=q.front().y;
        if(d>dis[u]){
            //q.pop();
            //continue;
        }
        else if(d==dis[u]){
            cnt[u]++;
            //q.pop();
            //continue;
        }
        else if(d<dis[u]){
            dis[u]=d;
            cnt[u]=1;
        }
        int l=a[u].size();
        for(int i=0;i<l;i++){
            int v=a[u][i];
            q.push({v,d+1});
        }
        q.pop();
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            a[i].clear();
            cin>>c[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(c[j]-c[i]<=m)a[i].push_back(j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            slove(i);
            for(int j=i+1;j<n;j++){
                if(cnt[j]==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    int Oct31=0,Dec25=1;
    return (Oct31==Dec25);
}
