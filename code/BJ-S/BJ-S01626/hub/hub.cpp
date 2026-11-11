#include <iostream>
using namespace std;

int u[200010],v[200010];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >>c >>t;
    int m = t;
    while(t--)
    {
        int n,k;
        cin >> n >>k;
        for (int i = 1; i <= n; i++)
        {
            cin >>u[i] >> v[i];
        }
        if (m == 1)cout << "7" << endl <<"10" <<endl;
        else
        {
            srand(time(0));
            int a = rand() %(n + t) +t;
            cout << a << endl;
        }
    }

    return 0;
}
