#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    string s;
    for(long long i =1;i <= n;i++){
        long long x;
        cin >> x;
        string s1;
        cin >> s1;
        for(long long j = 0;j < x;j++)s += s1;
    }
    string s1;
    long long num = 0;
    for(long long i = 0;i <= s.size()/2;i++){
        s1[i] = s[s.size()-1-i];
        if(s[i] != s1[i])num++;
    }
    cout << num;
    return 0;
}
