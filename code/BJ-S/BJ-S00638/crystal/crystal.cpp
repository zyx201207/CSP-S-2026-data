#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N];
int c[N];
void solve1(){
    int maxn=0;
    for(int i=2;i<=n;i++){
        int now=0;
        int ans=0;
        for(int j=i;j>=1;j--){
            if(now+a[i]-a[j]>m) break;
            ans++;
            now+=a[i]-a[j];
        }
        maxn=max(maxn,ans);
    }
    cout << maxn;
}
void solve2(int x){
    int ans=0,sum=0;
    for(int i=n-1;i>=1;i--){
        if(ans+ans+x>m) break;
        sum++;
        ans+=ans+x;
    }
    cout << sum+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n>>m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    if(n<=5000){
        solve1();
        return 0;
    }
    int f=1;
    for(int i=1;i<=n;i++){
        c[i]=a[i]-a[i-1];
        if(c[i]!=c[i-1] and i>2) f=0;
    }
    if(f) solve2(c[2]);
    else{
        solve1();
    }
    return 0;
}
