#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n+5],ans[m+5];
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++){
        vector<int> v;
        for(int j = i;j<=n;j++){
            if(a[i]>v[v.size()-1]) v.push_back(a[i]);
        }
        for(auto i:v) ans[i]++;
    }
    for(int i = 1;i<=m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
