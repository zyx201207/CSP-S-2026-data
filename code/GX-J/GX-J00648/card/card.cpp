#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 500;

int a[N];
int n , m;
int ans[N];
string s;

void bl(int c){
    int l = s.size();
    for(int i = 0; i < l; i++){
        if(s[i] == c + '0'){
            for(int j = i; j < l; j++){
                s[j] = '0';
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int I = 1; I <= n; I++){
        s = "";
        for(int i = I; i <= n; i++){
            bl(a[i]);
            s += a[i] + '0';
        }
        for(int i = 1; i <= m; i++){
            for(int j = 0; j < n; j++) if(s[j] == i + '0') ans[i]++;
        }
    }

    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}