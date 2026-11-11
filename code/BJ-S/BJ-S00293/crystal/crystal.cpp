#include<bits/stdc++.h>
using namespace std;

const int N=500005;
long long v[N];

long long n,m;
vector<long long> path;
long long ans=0;
void dfs(long long steps,long long value){
    if(steps==n+1){
        long long maxi=LLONG_MIN;
        for(long long i:path){
            maxi=max(i,maxi);
        }
        long long cnt=0;
        for(long long i:path){
            cnt+=maxi-i;
        }
        if(cnt==m){
            ans=max(ans,value);
        }
        return;
    }
    path.push_back(v[steps]);
    dfs(steps+1,value+1);
    path.pop_back();
    dfs(steps+1,value);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);//开注释
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>v[i];
    }
    dfs(1,0);
    cout<<ans<<'\n';
    return 0;
}
