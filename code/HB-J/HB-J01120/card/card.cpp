#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N], fa[N];
deque<int> dq;
bool v[N];
map<int, int> mp;
map<int, int> mp2;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++){
        for(int j = i; j <= n; j++){
            if(v[i]){
                for(int k = mp[a[j]]; k <= j; k++)
                    dq.pop_back();
                dq.push_back(a[j]);
                continue;
            }
            v[i] = 1;
            mp[a[j]] = j;
        }
        while(!dq.empty()){
            mp2[dq.front()]++;
            dq.pop_front();
        }
    }
    for(int i = 1; i <= n; i++)
        if(mp2[a[i]] != 0)
            cout << mp2[a[i]] << ' ';
    return 0;
}
