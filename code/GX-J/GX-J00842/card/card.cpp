#include <bits/stdc++.h>
using namespace std;

int n, m, cnt=1;
queue<int> q;
int a[500005], b[300005], c[300005];
int main(){
    //freopen("card.in", "r", stdin);
    //freopen("card.out", "w", stdout);
    cin >> n >> m;
    int u=1, uu=n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    while(uu){
        q.push(a[u]);
        c[q.back()]++;
        if(c[q.back()]>=2){
            int o=q.back();
            int xo=q.front();
            while(xo!=o){
                q.push(q.front());
                q.pop();
                xo=q.front();
            }
            int k=q.size();
            while(k>1){
                q.pop();
            }
        }
        if(u==n){
            u=cnt;
            cnt ++;
            uu--;
            for(int i=1; i<=m; i++){
                b[i] += c[i];
            }
        }
        u ++;
    }
    for(int i=1; i<=m; i++) cout << b[i] << " ";
    return 0;
}
