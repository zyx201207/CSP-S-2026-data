#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    string s="";
    long long n=0,a=0,cnt=0;
    char c;
    for(int i=1;i<=n;i++){
        cin >> a >> c;
        for(int j=1;j<=a;j++)s+=c;
    }
    for(int i=1;i<=s.size()/2;i++){
        if(s[i]!=s[s.size()+1-i])cnt++;
    }
    cout << cnt;
    return 0;
}
