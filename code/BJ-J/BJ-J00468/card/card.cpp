#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int card[100001], num[100001], temp[100001], address[100001], ans[100001];
    memset(card, 0, sizeof(card));
    memset(num, 0, sizeof(num));
    memset(temp, 0, sizeof(temp));
    memset(address, 0, sizeof(address));
    memset(ans, 0, sizeof(ans));
    for(int i=1; i<=n; i++){
        cin >> card[i];
        num[card[i]]++;
    }
    for(int i=1; i<=n; i++){
        memset(temp, 0, sizeof(temp));
        memset(address, 0, sizeof(address));
        for(int j=i; j<=n; j++){
            if(temp[card[j]] > 0){
                int ad = address[card[j]];
                for(int t=ad; t<j; t++){
                    address[card[t]]=0;
                    temp[card[t]] = 0;
                    ans[card[t]]--;
                }
            }
            temp[card[j]]=1;
            address[card[j]]=j;
            ans[card[j]]++;
        }
    }
    for(int i=1; i<=m; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
