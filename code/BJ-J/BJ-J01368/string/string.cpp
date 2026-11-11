#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in",stdin,"r");
    freopen("string.out",stdout,"w");

    int n,sum = 0;
    string s = "";
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a;
        char str;
        cin >> a >> str;
        for(int j = 1; j <= a; j++) s += str;
    }
    int l = 0,r = s.size() - 1,ans = 0;
    while(l < r){
        if(s[l] != s[r]) ans++;
        l++;
        r--;
    }
    cout << ans << endl;
    return 0;
}