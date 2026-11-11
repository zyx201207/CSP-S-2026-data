#include<iostream>
#include<cstring>
using namespace std;

int a[200005];
int box[3005];
int c[3005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    bool b = true;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] < a[i-1]){
            b = false;
        }
    }
    if(b){
    int cnt = 1;
        for(int i = 1; i <= n; ++i){
            memset(c, 0, sizeof(c));
            cnt = 1;
            for(int j = i; j <= n; ++j){
                if(c[cnt-1] == a[j]){
                    c[cnt-1] = 0;
                    cnt--;
                }
                c[cnt++] = a[j];
            }
            for(int i = 1; i <= cnt; ++i){
                box[c[i]]++;
            }
        }
        for(int i = 1; i <= m; ++i){
            cout << box[i] << ' ';
        }
        return 0;
    }
    int cnt = 1;
    for(int i = 1; i <= n; ++i){
        memset(c, 0, sizeof(c));
        cnt = 1;
        for(int j = i; j <= n; ++j){
            for(int k = 1; k <= cnt; ++k){
                if(c[k] == a[j]){
                    for(int o = cnt; o >= k; --o){
                        c[o] = 0;
                    }
                    cnt = k;
                }
            }
            c[cnt++] = a[j];
        }
        for(int i = 1; i <= cnt; ++i){
            box[c[i]]++;
        }
    }
    for(int i = 1; i <= m; ++i){
        cout << box[i] << ' ';
    }
    return 0;
}