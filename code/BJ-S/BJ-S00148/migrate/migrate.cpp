#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb emplace_back
#define mid ((l+r)>>1)
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e6+5;
int n,d,a[N];
int check(int l,int r){
    int now=l,la=l;
    int cnt=0;
    while(now!=r){
        while(a[now+1]-a[la]<=d && now<r)now++;
        if(now==r)break;
        int nx=now;
        while(a[nx+1]-a[now]<=d && nx<r)nx++;
        if(a[nx]-a[now-1]<=d)cnt++;
        if(now!=2 && a[nx]-a[now-2]<=d)cnt++;
        la=now;
    }
    return (cnt==1);
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(check(i,j))ans++;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int AC,T;
    cin>>AC>>T;
    while(T--)solve();
    return 0;
}