#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5, M = 3e5+5;

int n, m, a[N], pos[M], ans[M];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    pos[a[n]] = n + 1, a[n+1] = a[n];

    for(int g=1; g<=n; g++){
        int i = g, x = a[g];
        while(i <= n)
            i = pos[a[i]], ans[a[i]]++, i++;
    }

    for(int i=1; i<=m; i++)
        cout << ans[i] << ' ';

    return 0;
}
