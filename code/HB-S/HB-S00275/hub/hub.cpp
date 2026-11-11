#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
int n,k;
int chs;
int book[1000005];
vector<int> G[1000005];
int dfs(int u,int fa,int len){
    if((chs>>(u-1))&1) return len;
    int res=1e9;
    for(int v:G[u]){
        if(v==fa) continue;
        res=min(res,dfs(v,u,len+1));
    }
    return res;
}
void dfs2(int u,int fa){
    book[u]=1;
    for(int v:G[u]){
        if(v==fa) continue;
        if(((chs>>(v-1))&1)&&(!book[v])){
            dfs2(v,u);
        }
    }
}
void solve1(){
    int res=1e9;
    for(int i=0;i<=(1<<n)-1;i++){
        chs=i;
        int maxn=0;
        int cnt=0;
        int flag=0,last=-1;
        for(int j=1;j<=n;j++){
            if((i>>(j-1))&1){
                cnt++;
            }
            book[j]=0;
        }
        int cntt=0;
        for(int j=1;j<=n;j++){
            if((i>>(j-1))&1){
                if(!book[j]){
                    cntt++;
                    dfs2(j,0);
                }
            }
        }
        if(cnt!=k||cntt>2) continue;
        for(int j=1;j<=n;j++){
            if(!((i>>(j-1))&1)){
                maxn=max(dfs(j,0,0),maxn);
            }
        }
        res=min(res,maxn);
    }
    cout<<res<<"\n";
}
void solve2(){
    int m=n/2;
    if(k>=m){
        cout<<"1\n";
        return;
    }
    int mid=m/2;
    int ld=mid-1,rd=mid+1;
    int lk=k/2;
    int rk=k-lk;
    cout<<max({2,ld-lk+1+1,m-(rd+rk-1)+1})<<"\n";
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            G[i].clear();
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(k==n){
            cout<<"0\n";
            continue;
        }
        if(c<=3) solve1();
        else if(c>=13&&c<=14) solve2();
    }
    return 0;
}