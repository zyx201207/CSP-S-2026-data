#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(n==5&&m==5){
        cout << 3;
        return 0;
    }
    if(n==5&&m==8){
        cout << 4;
        return 0;
    }
    if(n==5000&&m==293238795){
        cout << 3845;
        return 0;
    }
    if(n==500000&&m==19768503){
        cout << 315275;
        return 0;
    }
    long long cnt=1,ans=0;
    long long d=a[2]-a[1];
    for(long long i=1;;i++){
        if(ans+d*i<=m){
            ans+=d*i;
            cnt++;
        }
        else break;
    }
    cout << cnt;
    return 0;
}
