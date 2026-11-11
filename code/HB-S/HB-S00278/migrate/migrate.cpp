#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int b,t,n,d,c[N];
long long x[N];
struct node{int l,r;}a[N];
void add(int o){
    for (int i=o;i<=n;i+=i&(-i)){
        c[i]++;
    }
}
int query(int o){
    int cnt=0;
    for (int i=o;i;i-=i&(-i)){
        cnt+=c[i];
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>b>>t;
    while (t--){
        cin>>n>>d;
        memset(c,0,sizeof c);
        for (int i=1;i<=n;i++) cin>>x[i];
        x[n+1]=1000000000000000001;
        for (int i=1;i<n;i++){
            int p=upper_bound(x+1,x+n+1,x[i]+d)-x;
            a[i]={i,p-1};
        }
        long long ans=0;
        for (int i=n-1;i>=1;i--){
            ans+=n-i-1-query(a[i].r);
            add(a[i].l);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
