#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
int ss;
struct node{
    int l;
    char c;
};

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string s;
    string h1, h2;
    int dp[N][N];
    node a[N];
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].l >> a[i].c;
        ss += a[i].l;
        for(int j = 1; j <= a[i].l; j++)
            s.push_back(a[i].c);
    }
    if(ss % 2){
        for(int i = 0; i < ss / 2; i++)
            h1 += s[i];
        for(int i = ss / 2 + 2; i < ss; i++)
            h2 += s[i];
        h1 = ' ' + h1;
        h2 = ' ' + h2;
        for(int i = 1; i <= int(h1.size()); i++){
            for(int j = 1; j <= int(h2.size()); j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(h1[i] == h2[j])
                    dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
            }
        }
        cout << ss / 2 - dp[h1.size()][h2.size()];
    }
    else{
        for(int i = 0; i < ss / 2; i++)
            h1 += s[i];
        for(int i = ss / 2 + 1; i < ss; i++)
            h2 += s[i];
        h1 = ' ' + h1;
        h2 = ' ' + h2;
        for(int i = 1; i <= int(h1.size()); i++){
            for(int j = 1; j <= int(h2.size()); j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(h1[i] == h2[j])
                    dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
            }
        }
        cout << ss / 2 - dp[h1.size()][h2.size()];
    }
    return 0;
}
