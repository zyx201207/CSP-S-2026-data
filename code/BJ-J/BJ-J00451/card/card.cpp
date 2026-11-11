#include<cstdio>
#include<map>
#include<vector>
#include<iostream>

using namespace std;


vector<int>a;
int b[1000000];
int ans[1000000];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        a.push_back(k);
    }
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            if (b[a[j]] == 0){
                b[a[j]]+= 1;
            }
            else {
                for (int c = 1; c <= m; c++){
                    b[c] = 0;
                }
                b[a[j]]+= 1;
            }
        }
        for (int c = 1; c <= m; c++){
            ans[b[c]]++;
                }
        for (int c = 1; c <= m; c++){
                    b[c] = 0;
                }
    }
    for (int i = 1; i <= m; i++){
        printf("%d ", ans[m]);
    }
    return 0;
}
