#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+5;
int n, m, a[N], last[N], cnt[200005];
vector<int> v;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        last[a[i]] = i;
    }
    for(int i=1; i<=n; i++){
            v.clear();
        for(int j=i; j<=n; j++){
            j = last[a[j]];
            v.push_back(a[j]);
        }
        for(int j=0; j<v.size(); j++){
            cnt[v[j]]++;
        }
    }

    for(int i=1; i<=m; i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
