#include <bits/stdc++.h>
using namespace std;
string s;
int n,cnt = 0,jsq=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int st[n];
    char sto[n];
    string a[n];
    for(int i = 0;i < n;i++){
        cin >> st[i];
        cin >> sto[i];
        for(int j = 1;j <= st[i];j++){
            a[i] += sto[i];
        }
        s += a[i];
    }
    for(int i = n;i > 0;i--){
        if(s[cnt]!=s[i])
            jsq++;
        cnt++;
    }
    if(jsq!=0)
        jsq--;
    cout << jsq;
    return 0;
}
