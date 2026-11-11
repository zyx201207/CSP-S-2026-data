#define fastio ios::sync_with_stdio(0);cin.tie(0);
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int maxn=5e5+35;

int n;
ll m;
ll a[maxn];
ll qzh[maxn];
void input(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        qzh[i]=qzh[i-1]+a[i];
    }
}

bool check(int len){
    for(int i=1;i+len-1<=n;++i){
        int j=i+len-1;
        ll mx=a[j];
        ll sum=qzh[j]-qzh[i-1];
        ll tow=mx*len;
        if(tow-sum<=m) return 1;
    }
    return 0;
}

void solve(){
    int l=1,r=n+1;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    printf("%d\n",l-1);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    fastio;
    input();
    solve();
    return 0;
}
