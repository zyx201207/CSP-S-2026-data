#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10, N = 3e5 + 10;
priority_queue<pair<int, int> > vivi, qu;
int n, m, a[M];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    int vis[m + 10][5005], num[m + 10];
    memset(vis , 0, sizeof(vis));
    memset(num , 0, sizeof(num));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        vis[a[i]][1]++;
        int t = vis[a[i]][1] + 1;
        vis[a[i]][t] = i;
        if(!vis[a[i]][0]){
        vis[a[i]][0] = 1;
        }
        else{
            vivi.push({(-1 * vis[a[i]][t - 1]), (-1 * vis[a[i]][t])});
        }
    }
    for(int i = 1; i <= n; i++){
            while(!qu.empty()){
                if((-1 * vivi.top().first) >= i)
                vivi.push({qu.top().first, qu.top().second});
                qu.pop();
            }
        for(int j = i; j <= n; j++){
            if(vivi.empty()){
                for(int k = j; k <= n; k++)
                    num[a[k]]++;
                break;
            }
            while((-1 * vivi.top().first) < j){
                qu.push({vivi.top().first, vivi.top().second});
                vivi.pop();
            }
            if((-1 * vivi.top().first) == j){
                j = -1 * vivi.top().second - 1;
                qu.push({vivi.top().first, vivi.top().second});
                vivi.pop();
            }
            else{
                    num[a[j]]++;
            }
        }
    }
    for(int i = 1; i <= m; i++) cout << num[i] << ' ';
    return 0;
}