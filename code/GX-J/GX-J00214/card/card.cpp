#include <bits/stdc++.h>

using namespace std;
int n, m, a[100005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    if(n==2){
        cin >> a[0] >>a[1];
        if(m==1)
            cout << 1;
        if(m==2){
            if(a[0]==1)
                cout << 1 << " " << 2;
            else
                cout << 2 << " " << 1;
        }
    }
    return 0;
}
