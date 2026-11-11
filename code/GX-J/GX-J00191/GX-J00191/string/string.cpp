#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int a;
    string c;
    cin >> n;
    string s;
    for(int i=1;i<=n;i++){
        cin >> a >> c;
        for(int i=1;i<=a;i++){
            s=s+c;
        }
    }
    int cnt=0;
    for(int i=0;i<=s.size()/2;i++){
        if(s[i]!=s[s.size()-i]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
