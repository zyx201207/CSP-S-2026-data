#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n, m;
long long maxans;
long long v[N];
bool flag[N];
void dfs(int cnt,long long ans){
    if(cnt==0){
        maxans=max(maxans, ans);
        return ;
    }
    if(cnt==m){
        for(int i=1;i<=n;i++){
            flag[i]=1;
            dfs(cnt-1, v[i]);
            flag[i]=0;
        }
    }else{
        for(int i=1;i<=n;i++){
            if(flag[i]==0)flag[i]=1;
            else continue;
            long long sum=( (v[i]) & (ans) );
            dfs(cnt-1, sum);
            flag[i]=0;
        }
    }


}
int main(){
    /*
    ben ti zhi neng de 45 fen
    qian si ti yi gong 100+48+45=193fen wo yao shang 200
    */
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    dfs(m, 0);
    cout<<maxans;
    return 0;
}
