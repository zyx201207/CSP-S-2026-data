#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long a[n],su = 0;
    string s,x;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
        cin>>x[i];
    }
    for(int j = 1;j <= n;j++)
    {
        if(x[j] == x[n])
        {
            cout<<"0";
        }
    }
    return 0;
}
