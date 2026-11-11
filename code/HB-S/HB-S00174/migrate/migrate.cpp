#include <iostream>
#include <vector>
using namespace std;
int c,q,n;
long long a[2000005];
long long d,x;
vector<long long> dis;
long long dfs(int start){
    if(a[start]) return a[start];
    if(start>=n) return 0;
    if(dis[start]+d>=dis.back()) return 0;
    int fnext=n,snext=n;
    for(int i=start+1;i<n;i++){
        if(dis[start]+d>=dis[i]){
            snext=fnext;
            fnext=i;
        }
    }
    long long ans=dfs(fnext);
    if(snext!=n&&dis[snext]+d<=dis.back()&&dis[snext]+d>=dis[fnext+1]) ans++;
    a[start]=ans;
    return ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>q;
    while(q--){
        dis.clear();
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x;
            dis.push_back(x);
        }
        long long ans;
        for(int i=0;i<n;i++){
            ans+=dfs(i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}