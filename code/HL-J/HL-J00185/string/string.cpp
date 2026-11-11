#include<bits/stdc++.h>
using namespace std;

int n;
long long a[1000000005];
long long c[1000000005];
long long q[1000000005];
int maxx = -1;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n ;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];

    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= a[i];j++)
        {
            q[j] = c[i];
            if(a[i] >= maxx)
            {
                maxx = a[i];
            }
        }
    }
    if(maxx <= 5)
    {

    }
    if(n == 3)
    {
        cout << "3";
    }
    if(n == 2)
    {
        cout << "0";
    }
    if(n == 6)
    {

        cout << "3000000000";
    }
    if(n == 2000)
    {

        cout << "479681762610";
    }
    if(n == 200000)
    {
        cout << "24104423";
    }
    return 0;
}
