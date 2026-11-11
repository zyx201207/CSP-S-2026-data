#include <bits/stdc++.h>
using namespace std;
int n,m;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector <int> a(n+5),cnt(m+5,0);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=m;i++) cout << 0 << " ";

    return 0;
}
