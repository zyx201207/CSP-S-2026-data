#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    cin >> n;
    for(int i=1;i<=n;i++){
        int t;
        char c;
        cin >> t >> c;
        while(t--){
            s.push_back(c);
        }
    }
    int cnt=0;
    for(int i=0;i<s.size()/2+1;i++){
        if(s[i]!=s[s.size()-i-1]){
            cnt++;
            s[s.size()-i-1]=s[i];
        }
    }
    cout << cnt;
    return 0;
}
