#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],ans;
bool cmp(int x,int y){
    return x<y;
}
long long need(long long l,long long r){
    return (r-l+1)*a[r]-(b[r]-b[l-1]);
}
long long find(int p){
    int l=1,r=p;
    while(l<r){
        int mid=(l+r)/2;
        if(need(mid,p)>m)l=mid+1;
        else r=mid;
    }
    return p-l+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
        ans=max(find(i),ans);
    }
    cout<<ans<<'\n';
    return 0;
}
