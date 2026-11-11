#include <bits/stdc++.h>
using namespace std;
int n;
int sum,mx;
string s;
bool is_hw(string x){
    int len = x.size();
    for(int i = 0;i < len;i++){
        if(x[i] != x[len - i - 1])return false;
    }
    return true;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        int x;
        char ch;
        cin >> x >> ch;
        sum += x;
        mx = max(mx,x);
        for(int j = 1;j <= x;j++)s += ch;
    }
    cout << sum - mx;
    return 0;
}
