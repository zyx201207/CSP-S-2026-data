#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 10, M = 3e5 + 10;

struct Node{
    int op, idx, t;
};

int n, m, a[N], cnt[N], ans[N];
int hd[N], edge[N];
vector<int> pos[N];
vector<Node > st[N];

bool cmp(Node p1, Node p2){
    return p1.t < p2.t;   
}

namespace sub1{
    int vis[N], book[N];
    void work(){
        for(int k = 0; k < n; k ++){
            if(k > 0) hd[a[k]]++;
            for(int i = 1; i <= n; i ++) edge[i] = 0;
            for(int i = k + 1; i <= n; i ++){
                //j yong lai pan duan i shi fou bei bao guo
                if(pos[a[i]].size() - hd[a[i]] > 1 && i == pos[a[i]][hd[a[i]]]){
                    edge[i] = a[i];
                }else if(pos[a[i]].size() - hd[a[i]] > 1 && i == pos[a[i]][pos[a[i]].size() - 1]){
                    edge[i] = -a[i];
                }
            }
            for(int i = 1; i <= m; i ++){
                cnt[i] = 0;
                book[i] = 0;
            }
            for(int i = k + 1, sum = 0; i <= n; i ++){
                if(edge[i] > 0){
                    book[a[i]] ++;
                    sum++;
                    cnt[a[i]]++;
                }else if(edge[i] < 0){
                    book[a[i]] --;
                    sum--;
                    cnt[a[i]]--;
                }
                if(sum - cnt[a[i]] == 0){
                    vis[a[i]] = 1;
                }
            }
            for(int i = 1; i <= m; i ++){
                ans[i] += vis[i];
                vis[i] = 0;
            }
        }
        for(int i = 1; i <= m; i ++){
            cout << ans[i] <<" ";
        }
    }
}

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    if(n <= 5000 && m <= 3000){  
        sub1::work();
        return 0;
    }
    for(int i = 1; i <= n; i ++){
        //j yong lai pan duan i shi fou bei bao guo
        if(pos[a[i]].size() > 1 && i == pos[a[i]][0]){
            edge[i] = a[i];
        }else if(pos[a[i]].size() > 1 &&  i == pos[a[i]][pos[a[i]].size() - 1]){
            edge[i] = -a[i];
        }
    }
    for(int i = 1, sum = 0; i <= n; i ++){
        if(edge[i] > 0){
            sum++;
            cnt[a[i]]++;
        }else if(edge[i] < 0){
            sum --;
            cnt[a[i]]--;
        }
        if(sum - cnt[a[i]] == 0){
            st[a[i]].push_back({1, i, 0} );
        }
    }

    /*
    for(int i = 1; i <= m; i ++){
        for(auto it : st[i]){
            cerr << it.first << " " << it.second.first << " " << it.second.second << "\n";
        }
        cerr << "\n";
    }       st[i].push();

    */

    
    for(int i = 1, j = 1; i <= n - 1; i ++){
        // i dai biao dang qian na yi ge bei tao tai
        if(pos[a[i]].size() > 1 && pos[a[i]][pos[a[i]].size() - 1] == i){
            st[a[i]].push_back({0, i, i});
            edge[i] = 0;
            if(j == i) j ++;
        }else{
            st[a[i]].push_back({0, i, i});
            edge[i] = 0;
            if(pos[a[i]].size() > 1) edge[pos[ a[i] ][ ++hd[a[i]] ]] = a[i];
            if(j == i) j ++;
            while(j <= n && edge[j] == 0){
                st[a[j]].push_back({1, j, i});
                j++;
            }
            if(edge[j] > 0){
                st[a[j]].push_back({1, j, i});
                j++;
            }
        }
        /*
        cout << "j = " << j << '\n';
        for(int k = 1; k <= n; k ++){
            cout << edge[k] <<  " ";
        }
        cout << "\n";
        */
    }
    
    /*
    for(int i = 1; i <= m; i ++){
        for(auto it : st[i]){
            cout << it.op << " " << it.idx << " " << it.t << "\n";
        }
        cout << "\n";
    
    }
    cout << "\n";
    */

    /**/
    memset(cnt, 0, sizeof cnt);
    for(int i = 1; i <= m; i ++){
        // sort(st[i].begin(), st[i].end(), cmp);
        int last = 0, sum = 0;
        for(int j = 0; j < (int)st[i].size(); j ++){
            int op = st[i][j].op, idx = st[i][j].idx, t = st[i][j].t;
            if(sum > 0){
                // cout << "+" << max(0, t - last) << "\n";
                ans[i] += max(0, t - last);
            }
            if(cnt[idx] == 1 && op == 0){
                sum--;
                cnt[idx] = 0;
            }else if(cnt[idx] == 0 && op == 1){
                sum++;
                cnt[idx] = 1;
            }
            last = t;
        }
        if(sum > 0){
            // cout << "wao mian +" << n - last<< "\n";
            ans[i] += n - last; 
        }
        // cout << "\n\n";
    }
    
    for(int i = 1; i <= m; i ++){
        cout << ans[i] << " ";
    }
    
    return 0;
}