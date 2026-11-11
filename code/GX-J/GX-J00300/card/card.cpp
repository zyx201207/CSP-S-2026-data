#include <bits/stdc++.h>
using namespace std;
int a[789987];
int i = 0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(i=1;i<=n;i++){
        if(a[i]=m){
            cout << '4';
        }
    }

    return 0;
}
