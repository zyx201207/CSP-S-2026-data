#include <iostream>
using namespace std;

const int N = 5e5 + 5;
const int M = 3e5 + 5;

int n, m;
int a[N], t[M];
int pos[N], last[M];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=n-1; i>=0; i--) {
        if (last[a[i]] == 0) last[a[i]] = i;
        pos[i] = last[a[i]];
    }

//    for (int i=0; i<n; i++) cout<<pos[i]<<' ';
//    cout<<endl;

    for (int i=0; i<n; i++) {

        for (int j=i; j<n;) {
            t[a[j]]++;
            j = pos[j] + 1;
        }
    }
    for (int i=1; i<=m; i++) cout<<t[i]<<' ';
    cout<<endl;
    return 0;
}

//   BJ-J00178/card/card.cpp
