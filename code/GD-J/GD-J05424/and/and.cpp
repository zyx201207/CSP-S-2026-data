#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m,ans = 0;
    cin >> n >> m;
    for (int i = 0;i < n;i++){
        cin>> a[i];
    }
    sort(a,a+n);
    for (int i = 1;i <= n;i++){
        int h = a[i] | a[i-1];
        ans = max(ans,h);
    }
    cout << ans;
    return 0;
}
