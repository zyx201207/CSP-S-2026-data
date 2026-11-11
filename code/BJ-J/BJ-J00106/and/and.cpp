#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e5+5;
long long a[N],b[N];
long long n,m,cnt=0;
bool cmp(long long x,long long y){
    return x>y;
}
void solve(){
    sort(b+1,b+1+cnt);
    cout<<b[1];
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(long long i=1;i<=m;i++){
        b[i]=a[i];
        cnt++;
    }
    solve();
    return 0;
}
