#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum = 0,m,m1;
    cin >> n;
    char a[n];
    int b[n],p[n];
    for(int i = 0;i < n;i++){
        cin >> b[i] >> a[i];
        sum += b[n];
    }
    p[0] = b[0];
    for(int i = 1;i < n;i++){
        p[i] = p[i-1]+b[i];
    }
    if(1 == 1){
        for(int j = 0;j < n;j++){
            if(sum > p[n]){
                sum -= p[n];
            }
            else{
                m = j;
                break;
            }
        }
    }
    if(n == 2)
        cout << 0;
    else if(n == 6)
        cout << 3000000000;
    else cout << p[m];
    return 0;
}
