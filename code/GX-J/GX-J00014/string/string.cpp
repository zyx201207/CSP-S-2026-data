#include <bits/stdc++.h>
using namespace std;

string s = "";
long long cnt = 1;
bool check(string x){
    string y = x;
    reverse(x.begin(),x.end());
    if (y  == x) return 1;
    return 0;
}

void compare(string x){
    long long left = 0,right = 0;
    string y = x;
    reverse(x.begin(),x.end());
    long long len = x.size() / 2;
    for (int i=0;i<len;i++){
        if (x[i] != y[i]) left++;
    }
    for (int i=len;i<x.size();i++){
        if (x[i] != y[i]) right++;
    }
    cnt = min(left,right);

    return;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        int num;
        char c;
        cin >> num >> c;
        for (int j=1;j<=num;j++) s += c;
    }
    if (check(s)){
        cout << 0;
        return 0;
    }
    compare(s);
    cout << cnt;
    return 0;
}
