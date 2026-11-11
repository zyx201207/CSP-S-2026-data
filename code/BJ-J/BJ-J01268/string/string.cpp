#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    while(n--){
        long long i;
        string x;
        cin >> i >> x;
        while(i--){
            s += x;
        }
    }
    string s1 = s;
    reverse(s.begin(),s.end());
    for(int i = 0;i<s.size()/2;i++){
        if(s[i]!=s1[i]) ans++;
    }
    cout << ans;
    return 0;
}
