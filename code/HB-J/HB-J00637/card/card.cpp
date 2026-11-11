#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    vector<int> cards;
    vector<int> ans;

    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n; i ++){
        int tmp;
        cin >> tmp;
        cards.push_back(tmp);
    }

    for (int i = 0;i < n;i ++){
        vector<int> a;
        int res = 0;
        for (int j = i;j <n;j ++){
            a.push_back(cards[i]);
            res += 1;
            for (int k = 1;k < n;k ++){
                if (a[k] == n){
                    a = {};
                    a.push_back(cards[i]);
                    res = 1;
                }
            }
        }
        cout << res << ' ';




    }
    return 0;
}
