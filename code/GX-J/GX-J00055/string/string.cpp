#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s;
    for(int i = 1;i <= n;i++){
        long long sum;
        string a;
        cin >> sum >> a;
        for(long long i = 1;i <= sum;i++){
            s += a;
        }
    }
    string s1;
    s1 = s;
    reverse(s.begin(),s.end());
    if(s == s1){
        cout << 0;
        return 0;
    }
    long long cnt=0;
    for(long long i = 1;i <= s.size();i++){
        long long j = s.size();
        if(s[i] != s[j]){
            cnt++;
        }
        j--;
    }
    cout << cnt/2;
    return 0;
}
