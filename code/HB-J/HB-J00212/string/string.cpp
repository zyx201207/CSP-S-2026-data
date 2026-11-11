#include <bits/stdc++.h>
using namespace std;

int n;   //gongjihang
int b;   //bianhuacishu
string a;   //zhengzhenshu
string c;   //zimu
string s;

int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdin);
    cin >> n;

    for(int i =0;i <n;i++){
        cin >> a >> c;
        for(int j = a[i];j >=1;j--){
            s += c[i];
        }
    }
    int m = a.size()/2+1;
    for(int i = 0 ;i < n ;i++){
        if(s[m+i] != s[m-i]){
            b++;
        }
    }
    //cout << s;

    cout << b;
    return 0;
}
