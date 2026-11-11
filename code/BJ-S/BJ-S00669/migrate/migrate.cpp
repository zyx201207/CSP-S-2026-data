#include<bits/stdc++.h>
using namespace std;
struct node{
int st;
int ti;
};
void zmjjkk(){
    vector<int>g[15702];
    long long n,d;
    cin>>n>>d;
    int x[2000005];
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(x[j]<=x[i]+d){
                g[j].push_back(i);
                g[i].push_back(j);
            }else break;
        }
        for(int j=i-1;j>=1;j--){
            if(x[j]>=x[i]+d){
                g[j].push_back(i);
                g[i].push_back(j);
            }else break;

        }
    }int ans=0;
    for(int i=1;i<n;i++){
    for(int j=i+1;j<=n;j++){
    queue<node>q;
    int tm=0,cnt=0;
        q.push({i,0});
        while(!q.empty()){
            node t=q.front();
            q.pop();
            if(t.st==j){if(tm==0){tm=t.ti;cnt++;}
            else if(tm==t.ti){
                cnt++;
            }else{
            break;}}
            for(auto x:g[t.st]){
                q.push({x,t.ti+1});
                }
        }if(cnt==2)ans++;
    }}cout<<ans<<endl;
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        zmjjkk();
    }
return 0;
}
