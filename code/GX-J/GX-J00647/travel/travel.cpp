#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a, b;
    int n, m;
    cin >> n >> a >> m >> b;
    if (n == m) cout << "1";
    else if (n != m) cout << "0";
    if(n == m && (a[0] == b[0] && a[1] == b[1]))cout << "1";
    else cout << "0";
    if(n == m && (a[0] == b[0]) && (a[1] == b[1]) && ((a[2] == 'A' && b[2] == 'C') || (a[2] == 'C' && b[2] == 'A') || (a[2] == 'A' && b[2] == 'B') || (a[2] == 'B' && b[2] == 'C') || (a[2] == 'D' && b[2] == 'F')|| (a[2] == 'B' && b[2] == 'A') || (a[2] == 'C' && b[2] == 'B') || (a[2] == 'F' && b[2] == 'D'))) cout << "1";
    else cout << "0";
    if(n == m && (a[0] == b[0]) && (a[1] == b[1]) && ((a[2] == 'A' && b[2] == 'B') || (a[2] == 'B' && b[2] == 'C') || (a[2] == 'D' && b[2] == 'F') || (a[2] == 'B' && b[2] == 'A') || (a[2] == 'C' && b[2] == 'B') || (a[2] == 'F' && b[2] == 'D'))) cout << "1";
    else cout << "0";
    return 0;
}
