#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","s",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long a;
    float c[15];
    string S;
    for(int i=1;i<=n;i++){
        cin >>a>>c[i];
        for(int j=1;j<=a;j++){
            S += c[i];
        }
     }
    return 0;
}
