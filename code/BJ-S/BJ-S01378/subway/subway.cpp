#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
bool v[500005];
vector<int>su[505];
vector<int>sut[505];
vector<int>st[500005];
int dfs(int x,int su_n,int e){
    if(x==e)return w[x];
    int cnt2=(su_n==0)?w[x]:sut[su_n][x];
    int cnt=2147483647;
    for(int i=0;i<st[x].size();i++){
        for(int j=0;j<su[i].size();j++){
            if(v[su[i][j]]==false){
                v[su[i][j]]=true;
                cnt=min(cnt,cnt2+dfs(su[i][j],i,e));
                v[su[i][j]]=false;
            }
        }
    }
    return cnt;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;int ans=0;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k,x,t;cin>>k;for(int j=1;j<=k;j++){
            cin>>x>>t;su[i].push_back(x);
            st[x].push_back(i);sut[i].push_back(t);
        }
    }for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;if(c<=6||(c>=20&&c<=23)){
            memset(v,0,sizeof(v));
            ans=dfs(x,0,y);
        }
    }cout<<ans<<'\n';
    return 0;
}
