#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >>n;
    int a,c;
    int m[105][n]={{}};
    for(int i=0;i<=a;i++){
        cin >> m[i][c];
    }
    int v[105][n]={{}};
    for(int i=n;i>=0;i--){
        for(int j=0;j<=n;j++)
            if(v[i][c]=m[i][c]) cout << 0;
    }
    return 0;
}
