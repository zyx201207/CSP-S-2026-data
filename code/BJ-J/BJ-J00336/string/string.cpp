#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,c,dif;
    string s1,s;
    cin >> n;
    dif = 0;
    s = "";
    s1 = "";
    for(int i=0;i<n;i++){
        cin >> c >> s1;
        for(int j = 0;j<c;j++){
            s+=s1;
        }
    }
    long long zzz = s.size();
    for(int i =0;i<zzz/2;i++){
        if (s[i]!=s[zzz-i-1]){dif++;}
    }
    cout << dif;
    return 0;
}

