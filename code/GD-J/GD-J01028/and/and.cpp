#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXNM=2e5+10;

int dp[MAXNM][MAXNM],a[MAXNM];
int countor(int x){
    int cnt=0;
    for(int i=0;i<32;i++){
        if((x>>i)&1){
            cnt++;
        }
    }
    return cnt;
}
int n,m;
int dfs(int x,int prev,int dep){
    if(dep==m||x==n){
        return prev&a[x];
    }
    return max(dfs(x+1,prev&a[x],dep+1),dfs(x+1,prev,dep));
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>a[MAXNM];
    }
    cout<<dfs(1,2147483647,1);
    
}
