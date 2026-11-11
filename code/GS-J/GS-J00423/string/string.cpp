#include <bits/stdc++.h>
using namespace std;

string s_in,s_out;
long long cnt;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,g; cin >> n;
    string k;
    for (long long i = 0;i < n;i++){
        cin >> g >> k;
        for (long long j = 0;j < g;j++) s_in += k;
    }

    stack <char> q;
    long long qn = (s_in.size() / 2);
    long long qm = (s_in.size() - qn);
    for (long long i = 0;i < qn;i++){
        q.push(s_in[i]);
    }
    for (long long i = 0;i < qm;i++){
        s_out += s_in[i];
    }
    for (long long i = 0;i < qn;i++){
        s_out += q.top();
        q.pop();
    }
    for (long long i = 0;i < s_in.size();i++){
        if (s_in[i] != s_out[i]) cnt ++;
    }
    cout << cnt;
    return 0;
}
