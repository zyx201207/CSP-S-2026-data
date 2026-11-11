#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<int> point = {0};
    vector<int> num = {};
    for(int i = 1;i <= n;i++){
        cin >> point[i];
    }
    for(int i = 1;i <= n;i++){
        vector<int> a = {};
        for(int j = i;j <= n;j++){
            a[j - i] = point[j];
            for(int x = 1;x <= a.size();x++){
                if(a[j - 1] == a[x]) {
                    for(int y = 1;y <= x;y++){
                        a[x] = 0;
                    }
                }
            }
        }
        for(int j = 1;j <= a.size();j++){
            if(a[j] == j) num[j] += 1;
        }
    }
    for(int i = 0;i < m;i++){
        cout << num[i] << " ";
    }
    return 0;
}

