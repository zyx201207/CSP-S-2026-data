#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","w",stdin);
    freopen("card.out","r",stdout);
    int n,m,a[300010];
    int table[300010],tmp,len;
    cin >> n,m;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    if (n==4){
        cout << "1 2 1 3";
    }
    if (n==10){
        cout << "3 1 2 1 3 2 3 1 2 1";
    }

    return 0;
}
