#include<bits/stdc++.h>
using namespace std;

long long n, m[2][1e9], mr[2][1e9];

int main(){
    freopen('string.in', 'r', stdin);
    freopen('string.out', 'w', stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        m[i][0] = a;
        m[i][1] = b;
    }
    long long cnt;
    for(int i = n/2; i < n; i++){
        cnt += m[i][0];
    }
}