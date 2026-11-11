#include<bits/stdc++.h>
using namespace std;

int n;
int a[200010];
char c[200010];

string hw(string s){
    string s1 = "";
    for(int i = s.size()-1; i >= 0; i--){
        s1 += s[i];
    }
    return s1;
}

string hw1(string s){
    string s1 = "";
    int b = s.size();
    for(int i = 0; i < b/2; i++){
        s1 += s[i];
    }
    for(int i = 0; i < b/2; i++){
        s1 += s[i];
    }
    return s1;
}
string hw2(string s){
    string s1 = "";
    int b = s.size()-1;
    for(int i = 0; i < b/2+1; i++){
        s1 += s[i];
    }
    for(int i = 0; i < b/2; i++){
        s1 += s[i];
    }
    return s1;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;

    for(int i = 1; i<=n; i++){
        cin >> a[i] >> c[i];
    }

    string s = "";
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=a[i]; j++){
            s += c[i];
        }
    }

    long long cnt = 0;
    if(hw(s) == s){
        cout << 0;
    }
    else if(s.size() % 2 == 0){
        string s1 = hw1(s);
        for(int i = 0; i<s.size(); i++){
            if(s[i] != s1[i]){
                cnt++;
            }
        }
        cout << cnt;
    }
    else if(s.size() % 2 == 1){
        string s1 = hw2(s);
        for(int i = 0; i<s.size(); i++){
            if(s[i] != s1[i]){
                cnt++;
            }
        }
        cout << cnt;
    }

    return 0;
}
