#include <bits/stdc++.h>
using namespace std;

long long l,r,n,sao,sum,a[200010];
string s;
char c[200010];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out", "w",stdout);

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> a[i] >> c[i];
    }

    for (int i=0;i<=n/2;i++){
        if (a[i]==a[n-1-i]){
            sao++;
            sum += a[i];
            a[i] = 0;
        }
        else break;
    }

    for (int i=sao;i<n-sao;i++){
        for (int j=0;j<a[i];j++){
            s = s + c[i];
        }
    }

    for (int i=0;i<s.size()/2;i++){
        if (s[i] != s[s.size()-1-i]){
            sum ++;
        }
    }

    cout << sum;
}
