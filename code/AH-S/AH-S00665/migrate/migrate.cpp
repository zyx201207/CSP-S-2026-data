#include<iostream>
#include<cstdio>
#include<queue>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],dp[2000005];
struct st{
    int pos,u;
};
int bfs(int s,int t){
    long long minn=1e17,cnt=1;
    for(int i=1;i<=n;i++)dp[i]=1e17;
    queue<st> q;
    q.push((st){s,0});
    while(!q.empty()){
        st f=q.front();
        q.pop();
        if(f.pos==t){
            if(minn==f.u)cnt++;
            if(f.u<minn){
                minn=f.u;
                cnt=1;
            }
            continue;
        }
        //cout<<f.pos<<" "<<f.u<<endl;
        for(int i=f.pos+1;i<=t;i++){
            if(x[i]-x[f.pos]<=d){
                if(f.u+1<=dp[i]){
                    q.push((st){i,f.u+1});
                    dp[i]=f.u+1;
                }
            }
            else break;
        }
    }
    //cout<<endl;
    return cnt;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(bfs(i,j)==2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
