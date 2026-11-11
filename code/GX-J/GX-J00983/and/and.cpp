#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool s[31][200020];
int cnt[30];
int n, m, flag;
vector<int> pass_idx;

int load_idx(int idx){
    int num = 0;
    for (int i=0;i<=30;i++){
        num += int(s[idx][i]) << i;
    }
    //cout << "NUM: " << num << endl;
    return num;
}

int solve(int i){
    for (;i>=0 && pass_idx.size() < m;i--){
        for (int j=0;j<=n;j++){
            if (s[j][i] == 1 && s[j][31] == false){
                //cout << "PASS: " << j << endl;
                pass_idx.push_back(j);
                s[j][31] = true;
            }
        }
    }
    while(true){
        int size = int(pass_idx.size());
        if (size <= m){
            int a = 0x7FFFFFFF;
            for (int i=0;i<size;i++){
                a &= load_idx(pass_idx[i]);
            }
            return a;
        } else {
            --i;
            for (int j=0;j<size;j++){
                if (!s[pass_idx[j]][i]){
                    //cout << "I=" << i << " J=" << j << " ERASE: " << pass_idx[j] << endl;
                    pass_idx.erase(pass_idx.begin() + j);
                    --j, --size;
                    if (size == m) {
                        break;
                    }
                }
            }
        }
    }
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        for (int j=30;j>=0;j--){
            if ((a >> j) & 1) {
                s[i][j] = 1;
                cnt[j]++;
            }
        }
    }

    for (int j=30;j>=0;j--){
        if (cnt[j] >= m) {
            cout << solve(j);
            return 0;
        }
    }
    cout << 0;
    return 0;
}
