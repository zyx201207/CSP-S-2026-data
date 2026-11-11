#include<bits/stdc++.h>

using namespace std;
int n, m, a[500010], cnt[500010];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        map<int, int> mp;
        vector<int> v;
        v.push_back(0);
        for(int j = i; j <= n; j++){
            if(mp[a[j]] == 0){
                mp[a[j]] = int(v.size());
                v.push_back(a[j]);
            }else{
                for(int k = mp[a[j]] + 1; k <= v.size(); k++){
                    mp[v[k]]= 0;
                    v.pop_back();
                }
            }
        }
        for(int j = 1; j < v.size(); j++){
            cnt[v[j]]++;
        }
    }
    for(int i = 1; i <= m; i++) cout << cnt[i] << ' ';
    return 0;
}
