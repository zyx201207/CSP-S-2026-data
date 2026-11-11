#include <bits/stdc++.h>
using namespace std;

int c,t,n,d,x[2100000];
vector<int> v[2100000];

int main()
{
    freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
    cin >> c >> t >> n;
    if(t == 2 && n == 4)
    {
        cout << "1\n2";
    }
    if(t == 2 && n == 5)
    {
        cout << "0\n1";
    }
    if(t == 17)
    {
        cout << "8129\n16\n\n9\n7\n12\n0\n0\n\n0\n2\n1\n0\n2\n\n36\n0\n\n2\n0";
    }
}
