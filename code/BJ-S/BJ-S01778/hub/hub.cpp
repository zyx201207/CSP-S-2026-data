#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,q;
int main()
{
    freopen("hub.in", "r",stdin);
    freopen("hub.out", "w",stdout);
    cin >>a >> b;
    for(long long i = 1; i <= b; i++)
    {
        cin >> c >>d;
        cout <<min(i,d) <<endl;
    }
    return 0;
}
