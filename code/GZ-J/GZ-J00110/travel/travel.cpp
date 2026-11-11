#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a [28][15];
    int c1,c2;
    for(int i =1;i <= 18;i++)
    {
        for(int j = 1;j <= 5;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i =1;i <= 18;i++)
    {
        for(int j = 1;j <= 5;j++)
        {
            cout << a[i][j];
        }
    }
    if(c1 == c2)
    {
        cout<<1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
