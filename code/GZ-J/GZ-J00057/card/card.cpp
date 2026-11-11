//兰玉昊 GZ-J00057 观山湖中学
#include<bits/stdc++.h>
using namespace std;

int n, m, a[500050], o[300050], ans[300050], b[500050], t;

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        t = 0;
        for(int j = i;j <= n;j++){
            if(o[a[j]]){
                for(int k = o[a[j]]+1;k <= t;k++) o[b[k]] = 0;
                t = o[a[j]]-1;
            }
            o[a[j]] = ++t;
            b[t] = a[j];
        }
        for(int j = 1;j <= m;j++){
            if(o[j]) ans[j]++;
            o[j] = 0;
        }
    }
    for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
	return 0;
}
