#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    string s;
    cin >> n;
    for(long long i = 1;i <= n;i++){
        long long a;
        char c;
        cin >> a >> c;
        while(a--) s += c;
    }
    string x = s.substr(0,s.size()/2),y = s.substr(s.size()/2+1,s.size());
    long long cnt = 0;
    for(int i = 0;i < s.size()/2;i++)
        if(x[i] != y[i]) cnt++;
    cout << cnt;
    return 0;
}
