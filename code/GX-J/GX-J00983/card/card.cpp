#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int a[500005], ans[300005];
vector<int> rec[300005];
vector<int> data;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=n;i>=1;i--){
        if (rec[a[i]].size() == 0){
            data.push_back(a[i]);
            rec[a[i]] = data;
        } else {
            data = rec[a[i]];
        }
        for (int j=0;j<data.size();j++){
            ans[data[j]]++;
        }
    }
    for (int i=1;i<=m;i++) cout << ans[i] << " ";

    return 0;
}
