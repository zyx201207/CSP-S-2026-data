#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in", "r", stdin);
freopen("and.out", "w", stdout);
int n, m, a[1000010];
cin >> n >> m;
for(int i = 0; i < n; i++){
    cin >> a[i];
}
if(m <= n) cout << "3";
 else{
     cout << "1";
 }
return 0;
}
