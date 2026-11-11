#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, a[N],ans;
signed main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
for(int i = 1;i <= n; i++){
    cin >> a[i];
            }
sort(a + 1, a + 1+ n);
int k = 0;
for(int i = 1,j = 1;i <= n; i++){
    while(j <= i&&k > n){
        j++;
        k = a[i] - a[j];
        }
ans = max(ans,i-j+1);
k+=(a[i+1]- a[i])*(i-j+1);
    }
cout << ans <<"\n";
return 0;
}
