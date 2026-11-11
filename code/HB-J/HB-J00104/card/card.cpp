#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n[500005],m;
    cin>>m;
    for(int i=1; i<=500005; i++)
    {
        cin>>n[i];
    }
    for(int i=1; i<=500005; i++)
    {
        cout << n[i] << " ";
    }
    return 0;
}
