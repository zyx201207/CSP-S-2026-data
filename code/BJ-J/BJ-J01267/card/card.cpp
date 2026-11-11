#include <bits/stdc++.h>
using namespace std;
long long a[1000860];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    cout << m << " " << a[0] << " " << n;


    return 0;
}
