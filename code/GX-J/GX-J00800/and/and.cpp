#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    long long ans = a[n];
    for(int i = n-1;i >= n-m+1;i--){
        ans &= a[i];
    }
    cout << ans;
    return 0;
}
