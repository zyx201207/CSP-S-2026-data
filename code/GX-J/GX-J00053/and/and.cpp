#include <bits/stdc++.h>
using namespace std;
long long nu[200005];
long long n,m;
int main ()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> nu[i];
    }
    sort (nu + 1,nu + n +1);
    for (int i = 1;i <= n;i++){
        if (i- 1){
            nu[i] &= nu[i];
        }
    }
    cout << nu[m];
    return 0;
}
