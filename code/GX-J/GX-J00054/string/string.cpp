#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x,cnt=0;
    char c;
    string s;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x >> c;
        for(int j=1;j<=x;j++) s+=c;
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]) cnt++;
    }
    cout << cnt;

    return 0;
}
