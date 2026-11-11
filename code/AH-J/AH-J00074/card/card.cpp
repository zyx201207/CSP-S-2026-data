#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];

    }
        for(int j=1;j<=m;j++){
            if(a[n]==j){
                cout << m << " ";
            }
            else {
                cout << a[j] << " ";
            }
        }

    return 0;
}
