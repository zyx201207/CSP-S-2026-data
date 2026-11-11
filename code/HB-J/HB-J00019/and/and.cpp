#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
long long n,m,ans;
long long a[N];
bool cmp(long long x,long long y){
    return x > y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n,cmp);
    for(int i = 1;i <= m;i++){
        if(i == 1) ans = a[i];
        else ans &= a[i];
    }
    cout << ans;
    return 0;
}
