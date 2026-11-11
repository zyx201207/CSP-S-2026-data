#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int a, b, m = 7e8, l=0,lk=0;
    cin >> a >> b;
    int c[a];
    for (int i = 1;i <= a;i++){
        cin >> c[i-1];
    }
    for (int j = 2;j<=a;j++){
        l = 0;
        for (int k = 1;k <= j;k++){
            l+=c[k-1];
        }
        m = l/j;
        for (int k = 1;k <= j;k++){
            if (c[k-1]<m){
                l += m-c[k-1];
            }
            else{
                l += c[k-1]-m;
            }
        }
        if (j>lk&&l<=b){
            lk = j;
        }
    }
    cout << lk;
    return 0;
}
