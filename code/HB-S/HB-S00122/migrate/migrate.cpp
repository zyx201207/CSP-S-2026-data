#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000001],in[2000001];
pair <long long,long long> dp[2000001];
vector <long long> v[2000001];
void tuopu(){
    long long ans=0;
    queue <long long> q;
    for (long long i=1;i<=n;i++){
        dp[i]={0,0};
        if (!in[i]) q.push(i),dp[i].first=1,dp[i].second=1;
    }
    while(!q.empty()){
        long long now=q.front();
        q.pop();
        for (long long i:v[now]){
            in[i]--;
            if (dp[i].first==0||dp[i].first>dp[now].first+1) dp[i].first=dp[now].first+1,dp[i].second=1;
            else if (dp[i].first==dp[now].first+1) dp[i].second++;
            if (!in[i]) q.push(i);
        }
    }
    for (long long i=1;i<=n;i++) ans+=(dp[i].second==2);
    cout<<ans<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for (long long i=1;i<=n;i++){
            cin>>x[i];
            for (long long j=1;j<i;j++){
                if (x[i]-x[j]<=d){
                    v[j].push_back(i);
                    in[i]++;
                }
            }
        }
        tuopu();
    }
    return 0;
}
