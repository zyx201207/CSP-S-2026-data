#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n,b[1000005];
    string a[100005],c;
    for(int i=1;i<=n;i++)
    {
        cin >> b[i] >> a[i];
        for(int j=1;j<=b[i];j++) c+=a[i];
    }
    cout << c;
}
