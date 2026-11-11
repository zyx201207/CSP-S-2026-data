#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
    cin >> c >> n >> m >> d >> q;
    vector<int>vec1(m+5);
    vector< vector<int> >a(d+5);
    for(int i = 1;i <= m;i++){
        cin >> vec1[i];
    }
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            a[i].push_back(j);
        }
    }
    return 0;
}
