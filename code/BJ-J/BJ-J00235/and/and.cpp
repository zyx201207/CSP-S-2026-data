#include <bits/stdc++.h>
using namespace std;
vector<int> oo;
vector<bool> kk;
int dg(int cann, int noww){
    if(cann == 0){
        return noww;
    }
    int maax = -1;
    for(int i = 0; i < oo.size(); i++){
        if(!kk[i]){
        kk[i] = 1;
        maax = max(maax, dg(cann - 1, noww & oo[i]));
        kk[i] = 0;
        }
    };
    return maax;
};

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        oo.push_back(0);
        cin >> oo[oo.size() - 1];
        kk.push_back(false);
    };

    cout << dg(m, 2147483647) << endl;
    return 0;
};