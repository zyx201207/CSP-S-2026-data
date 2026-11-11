#include<iostream>
#include<vector>
using namespace std;
const int mxn = 5e5 + 10;
int n, m, c[mxn], cnt[mxn];
vector<int> v;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            bool flag = false;
            if(j == i) v.push_back(c[j]);
            else{
                for(int k = j-1; k >= i; k--){
                    if(c[k] == c[j]){
                        flag = true;
                        for(int l = k; l <= j-1; l++) v.pop_back();
                        v.push_back(c[j]);
                        break;
                    }
                }
            }
            if(!flag && j != i) v.push_back(c[j]);
        }
        for(int x : v) cnt[x]++;
        v.clear();
    }
    for(int i = 1; i <= m; i++) cout << cnt[i] << " ";
    cout << endl;
    return 0;
}
