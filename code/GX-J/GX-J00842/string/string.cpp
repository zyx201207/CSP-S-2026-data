#include <bits/stdc++.h>
using namespace std;

int n, n1, num;
string s, s1;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        string y;
        cin >> x;
        n1 += x;
        cin >> y;
        for(int j=1; j<=x; j++){
            s += y;
        }
    }
    int n2=s.size()-1;
    int n3= (n2/=2)-1;
    for(int i=0; i<=n3; i++){
        if(s[i]!=s[n2+1-i]) num ++;
    }
    cout << num;
    return 0;
}
