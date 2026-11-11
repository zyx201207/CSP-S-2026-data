#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, m, ans;
int a[N];
map<int, int> mp;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        set<int> st;
        for(int j = i; j <= n; j++){
            if(!st.count(a[j])){
                st.insert(a[j]);
                mp[a[j]]++;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        cout << mp[i] << " ";
    }
    return 0;
}
