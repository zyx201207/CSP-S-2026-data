#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long cnt=0;
    bool flag=true;
    string s;
    cin >> n;
    for(int i=1;i<=n;i++){
        long long a;
        char b;
        cin >> a >> b;
        for(int j=1;j<=a;j++) s+=b;
    }
    for(int i=0;i<s.size()-1;i++) if(s[i]!=s[i+1]) flag=false;
    if(flag){
        cout << "0";
        return 0;
    }
    for(int i=1;i<=s.size()/2;i++){
        if(s[i]!=s[s.size()+1-i]) cnt++;
    }
    cout << cnt;
    return 0;
}
