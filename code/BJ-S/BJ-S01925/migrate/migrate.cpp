#include <bits/stdc++.h>
using namespace std;
long long QWETFDSA, QWERTYUIOP;//无意义的
long long n, m, x[2000005], a[2000005], b[2000005];
struct node{
    long long step, sum;
};
queue<node> q;
bool bfs(long long st, long long ed){
    while(!q.empty())q.pop();
    q.push(node{st, 0});
    int op = -1, top1 = -1;
    while(!q.empty()){
        node cnt = q.front();
        q.pop();
        if(a[cnt.step] >= ed){
            if(op == -1) op = cnt.sum, top1 = 1;
            else if(top1 == 2 && cnt.sum > op) return true;
            else if(top1 == 1 && cnt.sum > op) return false;
            else if(top1 == 2 && cnt.sum == op) return false;
            else if(top1 == 1 && cnt.sum == op){
                top1++;
                continue;
            }
        }
        if(a[cnt.step] == cnt.step+1){
            q.push(node{cnt.step+1, cnt.sum+1});
        }
        if(a[cnt.step] == cnt.step+2){
            q.push(node{cnt.step+2, cnt.sum+1});
            q.push(node{cnt.step+1, cnt.sum+1});
        }
        if(a[cnt.step] >= cnt.step+3){
            q.push(node{cnt.step+3, cnt.sum+1});
            q.push(node{cnt.step+2, cnt.sum+1});
            q.push(node{cnt.step+1, cnt.sum+1});
        }
    }
    return false;
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> QWETFDSA >> QWERTYUIOP;
    while(QWERTYUIOP--){
        cin >> n >> m;
        for(int i = 1;i <= n;i++) cin >> x[i];
        int cnt = 1;
        for(int i = 1;i <= n;i++){
            while(x[cnt] - x[i] <= m && cnt <= n){
                cnt++;
                if(cnt == n + 1) break;
            }
            a[i] = cnt - 1;
        }
        cnt = n;
        for(int i = n;i >= 1;i--){
            while(x[i] - x[cnt] <= m && cnt >= 1){
                cnt--;
                if(cnt == 0) break;
            }
            b[i] = cnt + 1;
        }
        long long ans = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] == i) continue;
            bool op11 = false;
            for(int j = i+3;j <= n;j++){
                if(op11 == true) break;
                if(a[j] == j) op11 = true;
                if(bfs(i, j) == true){
                    ans++;
                    //cout << i << " " << j << endl;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
