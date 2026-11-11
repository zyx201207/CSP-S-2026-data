#include<bits/stdc++.h>
using namespace std;
long long n,d,a[10010],ans,d_[10010][10010];
long long all_ans[10010][10010];
struct node{
    long long s,n,e,dis;
};
void solve(){
    queue<node> q;
    ans=0;

    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){d_[i][j]=0x3fffffff;all_ans[i][j]=0;}
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            q.push({i,i,j});
        }
    }
    while(!q.empty()){
        node now=q.front();
        q.pop();
        if(now.n!=now.e){
            for(long long i=now.n+1;i<=now.e;i++){
                if(abs(a[i]-a[now.n])<=d)q.push({now.s,i,now.e,now.dis+1});
                //cout<<"PUSHED S:"<<now.s<<" N:"<<now.n<<" E:"<<i<<" WAY:"<<now.way+"-->"+(char)(i+'0')<<endl;
            }
        }else{
            if(now.dis<d_[now.s][now.e]){
                all_ans[now.s][now.e]=1;
                d_[now.s][now.e]=now.dis;
            }else if(now.dis==d_[now.s][now.e]){
                all_ans[now.s][now.e]++;
                //cout<<now.s<<' '<<now.e<<" WAY:"<<now.way<<" DIS:"<<now.dis<<endl;
            }
            //cout<<now.s<<' '<<now.e<<" CANCELLEDWAY:"<<now.way<<" DIS:"<<now.dis<<endl;
        }
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            if(all_ans[i][j]==2){
                //cout<<i<<" J:"<<j<<" D:"<<d_[i][j]<<endl;
                all_ans[i][j]=0;
                all_ans[j][i]=0;
                ans++;
            }
        }
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(long long i=1;i<=n;i++)cin>>a[i];
        solve();
        cout<<ans<<endl;
    }
    return 0;
}
