#include<bits/stdc++.h>
using namespace std;

bool huiwei(string a){
    for (long long i=0; i<a.size()/2; i++){
        if (a[i] != a[a.size() - i - 1]){
            return false;
        }
    }
    return true;
}

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    string s;
    long long n;
    cin >> n;
    long long x;
    char a;
    for (long long i=1; i<=n; i++){
        cin >> x >> a;
        for (long long i=1; i<=x; i++){
            s += a;
        }
    }

    if (huiwei(s)){
        cout << 0;
        return 0;
    }

    long long cnt = 0;
    string b;
    for (long long i=0; i<s.size(); i++){
        b = s[i];
        if (s[s.size()-1-i] != s[i]){
            s.replace(s.size()-1-i, 1, b);
            cnt ++;
        }else{
            if (huiwei(s)){
                break;
            }
        }
    }

    cout << cnt;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
