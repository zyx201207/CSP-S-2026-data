#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int i1 = 1
    int n = 0,m = 0;
    cin >> n,m;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    for(int i = i1;i<n;i++){
        i++;
        break;
    }
    cout << n << m << i1;
    return 0;
    
}