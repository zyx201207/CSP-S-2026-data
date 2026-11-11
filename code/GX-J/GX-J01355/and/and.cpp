#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e5*2+10;
long long n,m;
long long a[MAXN];
void dfs(long long step,long long sum){
    if(step>m){
        cout<<sum;
        return;
    }
    for(long long i=0;i<n;i++){
            for(long long j=0;j<i;j++){
                sum=max(sum,a[i]&a[j]);
            }
    }
    dfs(step+1,sum);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(1,0);
    return 0;
}
