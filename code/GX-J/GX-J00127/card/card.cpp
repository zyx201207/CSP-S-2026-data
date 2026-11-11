#include <bits.stdc++.h>
using namespace std;
int n,m;
int main(){
    foren("card.in","r",stdin);
    foren("card.out","w",stdout);
    cin >> n>> m;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << n << " "<< m << " " << a[1];
    return 0;
}
