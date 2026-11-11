#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],dp[200010],ans = 0;
bool cmp(int x , int y){
    return x > y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m <= 0) cout<<0;
    for(int i = 1;i <= n;++i) cin>>a[i];
    sort(a + 1,a + n + 1,cmp);
    ans = a[1];
    for(int i = 2;i <= m;++i){
        ans = ans & a[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
