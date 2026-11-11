#include <bits/stdc++.h>
using namespace std;
const int M = 500005;
const long long N = 1e12+5;
long long n,m,a[M],f[M];
long long cnt,tot=1,ans,lst,add;
long long read(){
    long long x = 1,ret = 0;
    char c = getchar();
    while(c < '0' ||  c > '9'){
        if(c == '-')x = -1;
        c = getchar();
    }
    while(c >= '0' &&c <= '9'){
        ret = ret*10+c-'0';
        c = getchar();
    }
    return ret*x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = read();
    m = read();
    for(int i = 1; i <= n; i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i = 1; i < n; i++){
        f[i]=a[i+1]-a[i];
    }
    lst = n;
    for(int i = n; i; i--){
        if(cnt > m){
            lst--;add-=f[lst];
            tot=lst-i+1;
            cnt -= f[lst]*(tot);
        }
        tot = lst-i+1;ans = max(ans,tot);
        add += f[i-1];cnt += add;
    }
    cout << ans;
    return 0;
}