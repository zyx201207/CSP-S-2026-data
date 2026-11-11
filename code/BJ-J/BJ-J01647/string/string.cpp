#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    vector <int> x;
    vector <char> y;
    for(int i = 0;i < n;i++){
        cin >> x[i] >> y[i];
    }
    vector<char> s = {};
    int c = 0;
    for(int i = 0;i < n;i ++){
        for(int j = 0;i < x[i];j++){
            s.push_back(y[i]);
        }
    }
    int count = 0;
    for(int i = 1;i <= s.size()/2;i++){
        if(s[i] == s[s.size()-1]) continue;
        count++;
    }
    cout << count;
    return 0;
}
