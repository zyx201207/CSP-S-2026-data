#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans;
long long d;
long long a[2000001];
map<long long,int> f[2000001];
void dfs(long long s,long long w){
    f[s][w]++;
    if(f[s][w]==2) ans++;
    for(int i=w+1;i<=n;i++){
        if(a[i]-a[w]<=d) dfs(s,i);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(long long i=1;i<n;i++){
            dfs(i,i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
