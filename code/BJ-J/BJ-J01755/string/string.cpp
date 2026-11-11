#include <bits/stdc++.h>
using namespace std;
string s="";

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        int a;
        char c;
        cin >> a >> c;
        for(int i=1;i<=a;i++) s+=c;
    }
    long long l=s.size(),cnt=0;
    s=" "+s;
    for(int i=1;i<=ceil(1.0*l/2);i++){
        if(s[i]==s[l-i+1]) continue;
        cnt++;
    }
    cout << cnt;
    return 0;
}
