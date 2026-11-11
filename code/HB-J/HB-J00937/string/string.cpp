#include<bits/stdc++.h>
using namespace std;

int n;
string s = "";

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;

    for(int i = 1; i <= n; i++){
        int x;
        char s_cin;
        cin >> x >> s_cin;

        while(x--){
            s += s_cin;
        }
    }

    // cout << s << endl; // debug

    string st = "";
    string ed = "";

    for(long long int i = 0; i < s.size() / 2; i++){
        st += s[i];
    }
    for(long long int i = s.size() / 2 + 1; i < s.size(); i++){
        ed += s[i];
    }

    // cout << st << endl << ed << endl;

    long long int ans = 0;
    for(long long int i = 0; i < st.size(); i++){
        // cout << "st,ed:" << st[i] << " " << ed[ed.size() - i - 1] << endl;

        if(st[i] != ed[ed.size() - i - 1]){
            ans++;
        }
    }

    cout << ans;

    return 0;
}
