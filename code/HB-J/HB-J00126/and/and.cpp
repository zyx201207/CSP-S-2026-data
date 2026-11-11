#include <bits/stdc++.h>
using namespace std;
long long a[200005];
bool vis[200005];
long long maxx=-1;
long long n,m;
vector<long long> vec;
long long result(){
    long long r=vec.front();
    for(long long i=1;i<vec.size();++i){
        r&=vec[i];
    }
    return r;
}
void dfs(long long k){
    if(k==0){
        maxx=max(maxx,result());
        return;
    }
    for(long long i=1;i<=n;++i){
        if(vis[i]==1) continue;
        vis[i]=1;vec.push_back(a[i]);
        dfs(k-1);
        vis[i]=0;vec.pop_back();
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    long long e=-1;
    for(long long i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        e=max(e,a[i]);
    }
    if(n>2000) cout<<e;
    else{
        dfs(m);
        printf("%lld",maxx);
    }
    return 0;
}
