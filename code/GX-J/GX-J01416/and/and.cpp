#include<bits/stdc++.h>
using namespace std;

/*
string zhongEr(int a){
    string s;
    while(a!=0){
        s+= a%10+'0';
        a/=10;
    }
    reverse(s.begin(), s.end());
    return s;
}

string BJ(string x, string y){
    string z;
    if (x.size() != y.size()){
        x.insert(0, abs(x.size()-y.size()), "0");
        y.insert(0, abs(x.size()-y.size()), "0");
    }
    for (int i=0; i<x.size();i++){
        if (x[i] == y[i] && x[i] == '1'){
            z[i] = '1';
        }else{
            z[i] = '0';
        }
    }
    return z;
}

int Erzhong(string a){
    int s;
    for (int i=0; i<a.size(); i++){
        s += pow(2,i)*(a[i]-'0')
    }
    return s;
}
*/

int cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int a[1000100];
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    sort(a+1, a+n+1, cmp);
    cout << a[m];
    return 0;
}
