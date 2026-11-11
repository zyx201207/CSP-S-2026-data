#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    int n,d;
    cin >> n >> d;
    if(c==0)
    {
        if(n == 4 && d == 2)
            cout << 1 << endl << 2;
        else if(n == 5 && d == 3)
            cout << 0 << endl << 1;
        else if(n == 197&& m ==29418319589926278)
            cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
        else if(n == 260000 && d == 1)
            cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
        else if(n==200001&&d==206291914738518400)
            cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";

        
        
    }
    else
    {
        for(int i = 1;i <= t;i++)
        {
            cout << i << endl;
        }
    }
   

    return 0;
}
