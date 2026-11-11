#include<bits/stdc++.h>;
using namespace std;
long long n,m,ac[200005],ab[200005],maxx=-1e9;
void dfs(int cnt){
    if(cnt>n){
        long long ans=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(ac[i]==1){
                sum++;
                if(sum==1){
                    ans=ac[i]*ab[i];
                }
                else{
                    ans&=(ac[i]*ab[i]);
                }
            }
        }
        if(sum==m){
            maxx=max(maxx,ans);
        }
        return ;
    }
    for(int i=0;i<=1;i++){
        ac[cnt]=i;
        dfs(cnt+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ab[i];
    }
    dfs(1);
    cout<<maxx;
    return 0;
}
