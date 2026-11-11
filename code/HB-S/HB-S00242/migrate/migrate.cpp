#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+50;
int a[maxn];
int c,t;
int n,d;
int cnt[maxn];
int ans;
void dfs(int s,int e,int now,int k){
    if(now==e){
        cnt[k]++;
        ans=k;
        return ;
    }
    if(k>ans)return ;
    for(int t=n-now;t>=1;t--){
        int dis=a[now+t]-a[now];
        if(dis>d)continue;
        dfs(s,e,now+t,k+1);
    }
    return ;
}
void solve1(){
    int res=0;
    for(int i=1;i<=n-3;i++){
        for(int j=i+3;j<=n;j++){
            ans=0x3f3f3f3f;
            memset(cnt,0,sizeof(cnt));
            dfs(i,j,i,0);
            //cout<<"test: ";
            for(int i=1;i<=n;i++){
                //cout<<cnt[i]<<" ";
                if(cnt[i]!=0&&cnt[i]!=2)break;
                if(cnt[i]==2){
                    res++;
                    break;
                }
            }
            //cout<<endl;
        }
    }
    cout<<res<<endl;
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        memset(a,0,sizeof(a));
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        solve1();
    }

    return 0;
}