#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, f;
int a[N], s[N];
bool b[N];
vector<int> v;
int myfind(int x){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == x)
            return i;
    }
    return -1;
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            f = myfind(a[j]);
            if(f != -1){
                v.erase(v.begin() + f + 1, v.end());
            }else{
                v.push_back(a[j]);
            }
        }
        while(!v.empty()){
            b[v.back()] = 1;
            v.pop_back();
        }
        for(int j = 1; j <= m; j++){
            if(b[j]){
                s[j]++;
                b[j] = 0;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        cout << s[i] << " ";
    }

}
