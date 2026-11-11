#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t;
    string s,rs;
    cin >> t;
    for(int i=0;i<t;i++){
        int a;
        char b;
        cin >> a;
        cin >> b;
        for(int j=0;j<a;j++){
            s.push_back(b);
            rs.push_back(b);
        }
    }
    reverse(rs.begin(),rs.end());
    long long cnt=0;
    for(long long i=0;i<s.size();i++){
        if(s[i]!=rs[i]){
            cnt++;
        }
    }
    cout << cnt/2;
    return 0;
}
