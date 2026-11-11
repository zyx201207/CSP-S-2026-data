#include <bits/stdc++.h>
using namespace std;

struct str{
    int num;
    char a;
};

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;
    str s[n+10];
    for (int i=1;i<=n;i++){
        cin >> s[i].num >> s[i].a;
    }

    int m=0;
    for (int i=1;i<n;i++){
        if (s[i].a!=s[i+1].a){
            m++;
        }
    }
    if (m==0){
        cout << 0;
        return 0;
    }

    string k="";
    long long b=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=s[i].num;j++){
            k+=s[i].a;
            b++;
        }
    }

    int ans=0;
    for (long long i=b-1;i>=0;i--){
        if (k[i] != k[b-i-1]){
            ans++;
            k[i]=k[b-i-1];
            //cout << k << endl;
        }
    }
    cout << ans;

    return 0;
}
