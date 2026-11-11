#include <bits/stdc++.h>
#define N 500010
using namespace std;
int n, m, a[N], box[N], answer[N];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        deque <int> q;
        for(int j = i; j <= n; j++){
            if(!box[a[j]]){
                box[a[j]] = true;
                q.push_back(a[j]);
            } else {
                while(q.back() != a[j]){
                    box[q.back()] = false;
                    q.pop_back();
                }
            }
        }
        while(!q.empty()){
            int x = q.front();
            q.pop_front();
            answer[x]++;
        }
        for(int i = 1; i <= m; i++){
            box[i] = false;
        }
    }
    for(int i = 1; i <= m; i++){
        cout << answer[i] << ' ';
    }
}
