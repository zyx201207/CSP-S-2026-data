#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    unsigned long long sum = 0;
    string s;
    cin >> n;
    for(int i = 1;i <= n;i++){
        long long x;
        char c;
        cin >> x >> c;
        sum += x;
        for(int i = 1;i <= x;i++){
            s += c;
        }
    }
    string h = s;
    reverse(h.begin(),h.end());
    if(s == h){
        cout << 0;
        return 0;
    }
    unsigned long long k = sum/2;
    unsigned long long ans = k;
    for(int i = 0;i < k;i++){
        if(s[i] == s[sum-1-i]){
            ans-= 1;
        }
    }
    cout << ans;
    return 0;
}
