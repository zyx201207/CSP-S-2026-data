#include "bits/stdc++.h"
using namespace std;

int idx = 0;
int s[3000005];

bool empty() {
    return idx == 0;
}

void push(int x) {
    s[++idx] = x;
}

int top() {
    return s[idx];
}

void pop() {
    if(idx) idx--;
}

void clear() {
    idx = 0;
}


int use[300005];
int a[500005];
int res[300005];

int main() {

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        memset(use, 0, sizeof(use));
        clear();
        for(int j = i; j <= n; j++) {
            if(!use[a[j]]) {
                use[a[j]] = 1;
                push(a[j]);
            }
            else {
                while(!empty()) {
                    if(top() == a[j]) {
                        pop();
                        push(a[j]);
                        break;
                    }
                    else {
                        use[top()] = 0;
                        pop();
                    }
                }
            }

          //  cout << "st: \n";
           // for(int i = 1; i <= idx; i++) {
           //     cout << s[i] << ' ';
           // }
            //cout << '\n';

        }
        //cout <<"RES:\n";
        for(int i = 1; i <= idx; i++) {
            //cout << s[i] << ' ';
            res[s[i]]++;
        }

        //cout << "FInished! \n";
    }


    for(int i = 1; i <= m; i++) {
        cout << res[i] << ' ';
    }

    return 0;
}
