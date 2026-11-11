#include<bits/stdc++.h>
using namespace std;

int n, m, a[500005], book[500005];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i  = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        vector<int> v;
        for(int j = i;j <= n;j++){
            bool flag = true;
            int p = -1;
            for(int t = 0;t < v.size();t++){
                if(v[t] == a[j]){
                    flag = false;
                    p = t;
                    break;
                }
            }
            if(flag) v.push_back(a[j]);
            else{
                for(int t = p;t < v.size();t++){
                    v.pop_back();
                }
            }
        }
        for(int j = 0;j < v.size();j++){
            book[v[j]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << book[i] << " ";
    }
    return 0;
}
