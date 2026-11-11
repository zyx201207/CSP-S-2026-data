#include<iostream>
#include<algorithm>
using namespace std;
long n,m,ans = 0;
long a[200005];
bool cmp(long a,long b){
    return a > b;
}
long max(long c,long d){
    if(c > d) return c;
    return d;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1,cmp);
    for(int i = 1;i <= n - m;i++){
        long x = a[i];
        for(int j = i + 1;j <= i + m - 1;j++){
            x &= a[j];
        }
        ans = max(ans,x);
    }
    cout << ans;
    return 0;
}