#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct se{
    int x,id;
}d[N];
bool cmp(se u,se v){
    return u.x>v.x;
}
int sum[N],n,m,k[40],a[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    k[0]=1;
    for(int i=1;i<=34;i++){
        k[i]=k[i-1]*2;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int o=log2(a[i]);
        d[i].x=(int)ceil(a[i]-k[o]);
        d[i].id=i;
    }
    sort(d+1,d+n+1,cmp);
    int ans=a[d[1].id];
    for(int i=2;i<=m;i++){
        ans=(ans&a[d[i].id]);
    }cout<<ans;
    return 0;
}
