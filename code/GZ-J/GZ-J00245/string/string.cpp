//GZ-J00245
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    vector<char> s;
    for(int i = 0;i < n - 1;i++){
        int a;
        char b;
        cin>>a>>b;
        for(int j = 0;j < a;j++){
        s.push_back(b);
        }
    }
    int cnt = 0,l = s.size();
    for(int i = 0;i < l / 2;i++){
        if(s[i] != s[l - i - 1]) cnt++;
    }
    cout<<cnt;
    return 0;
}
