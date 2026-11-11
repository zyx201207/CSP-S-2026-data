#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int a[N], num[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> v;
    for (int i = 1; i <= n; i++){
        v.clear();
        for (int j = i; j <= n; j++){
            for (int k = 0; k < v.size(); k++)
                if(v[k] == a[j])
                    while(v.size() > k)
                        v.pop_back();
            v.push_back(a[j]);
        }
        for(const auto& x : v)
            num[x]++;
    }
    for (int i = 1; i <= m; i++)
        cout << num[i] << " \n"[i == n];
    return 0;
}
