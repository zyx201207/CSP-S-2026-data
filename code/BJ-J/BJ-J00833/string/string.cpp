#include <iostream>
#include <string>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, res = 0;
    cin >> n;
    char c[n+1];
    int num[n+1];
    for(int i = 1; i <= n; i++) cin >> num[i] >> [i];
    int l = i, r = n;
    while(l < r){
        int min=num[l]>num[r]?num[r]:num[l];
        num[l] -= min;
        num[r] -= min;
        if(c[l] = c[r]){

        }
    }
    return 0;
}
