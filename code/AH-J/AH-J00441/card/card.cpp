#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("cars.out","w",stdout);
    int n,m,b;
    cin >> n >> m;
    queue<int> a;
    for(int i=0;i<n;i++)
    {
        for(int i=0;i<n;i++)
        {
            cin >> b;
            a.push(b);

        }
        cout << n;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
