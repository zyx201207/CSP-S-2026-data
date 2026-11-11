#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 100;
int a[N];
int n,m;
int l,r;
int ans;
int cnt;
int len;
int x;
int read(){
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(!isdigit(ch)){
        if(ch == '-'){
            f = -1;
        }
        ch = getchar();
    }
    while(isdigit(ch)){
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x*f;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = read();
    m = read();
    for(int i = 1;i<=n;i++){
        a[i] = read();
    }
    sort(a+1,a+1+n);
    l = 1;
    r = 1;
    ans = 1;
    cnt = 0;
    while(l <= r && r <= n){
        if(cnt <= m){
            ans = max(ans,r-l+1);
            len = (r-l+1);
            r++;
            x = a[r] - a[r-1];
            cnt += x*len;
        }else{
            l++;
            ans = max(ans,r-l+1);
            x = a[r] - a[l-1];
            cnt -= x;
        }
    }
    cout<<ans;
    return 0;
}