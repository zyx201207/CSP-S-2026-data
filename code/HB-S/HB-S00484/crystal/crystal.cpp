#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[100000000];
long long n,m;
long long y = 0;
void dfs(long long c[500005],long long sum,long long cnt){
    long long x = 1;
    for(long long i = 0;i<n;i++){
        for(long long j = i+1;j<n;j++){
            if(a[i]==a[j]){
                x++;
            }
        }
        cnt = max(cnt,x);
        x = 1;
    }
    if(sum>0){
        b[y] = cnt;
        y++;
        for(long long i = 0;i<n-1;i++){
            if(c[i+1]!=c[i]){
                sum -= c[i+1]-c[i];
                c[i] = c[i+1];
                dfs(c,sum,cnt);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i = 0;i<n;i++){
        cin>>a[i];
    }
    bool f = 1;
    for(long long i = 0;i<n;i++){
        for(long long j = i+1;j<n;j++){
            if(a[i]!=a[j]){
                f = 0;
            }
        }
    }
    if(f){
        cout<<n;
        return 0;
    }
    stable_sort(a,a+n);
    bool flag = 1;
    long long h = a[1]-a[0];
    for(long long i = 1;i<n-1;i++){
        if(a[i+1]-a[i]!=h){
            flag = 0;
        }
    }
    if(flag){
        int g = 0,k = 0;
        while(m>0){
            k++;
            m -= g*h;
            g++;
        }
        cout<<k;
        return 0;
    }
    dfs(a,m,0);
    long long p = 0;
    for(long long i = 0;i<y;i++){
        if(b[i]>p){
            p = b[i];
        }
    }
    cout<<h;
    return 0;
}
