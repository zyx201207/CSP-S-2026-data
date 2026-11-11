#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

/*

    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    freeopen("migrate.in","r",stdin);
    freeopen("migrate.out","w",stdout);
    reopen("migrate.in","r",stdin);
    reopen("migrate.out","w",stdout);
    freopen("migrate.in","w",stdin);
    freopen("migrate.out","r",stdout);
*/
int c,t;
int n,d;


long long int x[509];




bool isSJDY(int b,int a)
{
    long long ct = 0;
    int ix = a;
    while (ix < b)
    {
        int i = ix;
        for(;i < n;i++)
        {
            if (x[i] - x[ix] > d) break;
        }
        if (x[i] - x[ix] > d) i--;
        ct++;
        ix = i;
    }
    queue<pair<int,int> > q;
    q.push({a,0});
    while (!q.empty())
    {
        auto z = q.front();
        q.pop();

    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n>> d;
        for (int i = 0; i < n;i++)
        {
            cin >> x[i];
        }
        long long ct = 0;
        for (int i = 1;i < n;i++)
        {
            for (int j = 1;j < i;j++)
            {
                if (isSJDY(i,j)) ct++;
            }
        }
        cout << ct;
    }

    return 0;
}
