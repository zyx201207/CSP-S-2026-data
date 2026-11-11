#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];
int ans[300005];

void work(int t){
    int tong[300005] = {};
    int tb[500005] = {};

    int cnt = 1;
    for(int i = t; i <= n; i++){
        tb[cnt] = a[i];
        tong[a[i]]++;
        //cout << "game:" << t << ", now add" << a[i] << endl;

        if(tong[a[i]] >= 2){
            //cout << "   find >=2, clear" << endl;

            int flag = 0;
            for(int j = 1; j < cnt; j++){
                if(tb[j] == a[i]){
                    flag = j;
                }
            }



            for(int j = flag + 1; j <= cnt; j++){
                tb[j] = 0;
            }

            cnt = flag + 1;

            for(int j = 1; j <= m; j++){
                tong[j] = 0;
            }

            for(int j = 1; j <= cnt; j++){
                tong[tb[i]]++;
            }

            //cout << "       now:";
            //for(int i = 1; i <= cnt; i++){
            //    cout << tb[i] << " ";
            //}
            //cout << endl;
        }
        else{
            cnt++;
        }
    }

    for(int i = 1; i <= cnt; i++){
        ans[tb[i]] ++;
    }

}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int t = 1; t <= n; t++){
        work(t);
    }

    for(int i = 1; i <= m; i++){
        if(ans[i] != 0){
            cout << ans[i] << " ";
        }
    }

    return 0;
}
//    4 3 1 2 1 3
//    10 3 3 1 2 1 3 2 3 1 2 1
// Trick||Treat!
