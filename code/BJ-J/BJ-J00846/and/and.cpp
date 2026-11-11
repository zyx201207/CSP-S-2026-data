#include <bits/stdc++.h>

using namespace std;

int ai[214514];
bool book[214514];
int maxn = 0, now;
int n, m;
//stack<int> st;

void dfs(int s, int pos){
    int nowt, t = -1;
    //cout << s << endl;
    if (s == m){
        if (now > maxn){
            //stack<int> tt = st;
            //while (tt.size()){
            //    cout << tt.top() << " ";
            //    tt.pop();
            //}
            //cout << endl;
            maxn = now;
            //cout << maxn << endl;
        }
        return;
    } else {
        if (pos > n){
            return;
        }
        for (int i = pos; i <= n && ai[i] >= maxn; i++){
            if (!book[i] && ((now & ai[i]) >= maxn) && (ai[i] != t)){
                //st.push(ai[i]);
                t = ai[i];
                nowt = now;
                now = now & ai[i];
                book[i] = 1;
                dfs(s+1, i + 1);
                book[i] = 0;
                now = nowt;
                //st.pop();
            }
        }
    }
}

bool cmp(int a, int b){
    return a > b;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    //cout << n << " " << m << endl;
    for (int i = 1; i <= n; i++){
        cin >> ai[i];
    }
    //cout << 1;
    sort(ai + 1, ai + n + 1, cmp);
    for (int i = 1; i <= n && ai[i] >= maxn; i++){
        //cout << ai[i] << endl;
        //st.push(ai[i]);
        book[i] = 1;
        now = ai[i];
        dfs(1, 1);
        book[i] = 0;
        //st.pop();
    }
    cout << maxn;
    return 0;
}
