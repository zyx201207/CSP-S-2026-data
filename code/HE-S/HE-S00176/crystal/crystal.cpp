#include   <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],s[N],c[N];
void solve(){
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i+=1)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i+=1){
        long long g=c[i-1]*(a[i]-a[i-1]);
        s[i]=s[i-1]+g;
        c[i]=c[i-1]+1;
    }
    for(int i=n;i>=1;i-=1){
        if(m>=s[i]){
            cout<<c[i];
            return;
        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
return 0 ;
}
