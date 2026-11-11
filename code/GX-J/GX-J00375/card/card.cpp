#include <bits/stdc++.h>
using namespace std;

int maim(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int ans[m];
    int c[m + 1][2];
    int P[101];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 101;j++){
            P[j] = 0;
        }
        for(int j = 1;j < m + 1;i++){
            c[j][0] = 0;
            c[j][1] = 0;
        }
        int top = 0;
        for(int j = i;j < n;i++){
            int h = a[j];
            if(c[h][0] == 1){
                top = c[h][1];
                for(int k = c[h][1];k < 101;k++){
                    c[P[k]][0] = 0;
                    c[P[k]][1] = 0;
                    P[k] = 0;
                }
            }else{
                P[top] = h;
                c[h][0] = 1;
                c[h][1] = top;
            }
        }
        for(int j = 1;j < m - 1;j++){
            ans[j - 1] += c[j][0];
        }
    }
    for(int i = 0;i < m;i++){
        cout << ans[i] << '\n';
    }

    return 0;
}
