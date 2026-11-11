#include <bits/stdc++.h>

using namespace std;
int a[200005], n, m, r;

int main()
{
    freopen("and.in", "r",stdin );
    freopen("and.out", "w", stdout);
    cin >>n >> m;
    int c = 0;//1 3 7 15 31
    //1 3 7      3 7 15     7 15 31
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n  ; j++)
        {
            int aaa;
            aaa = a[i] & a[j];
            for(int o = 1 ; o <= m - 2 ; o++)
           {
               aaa &= a[j + o];
            }
            //cout << aaa<<endl;

            if(aaa > c)
            {
                c = aaa;
            }

        }
    }
    cout << c;
    return 0;

}
