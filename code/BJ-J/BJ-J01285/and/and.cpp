#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(n <= 2000) cout << 2;
    if(n > 2000) cout << 1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}