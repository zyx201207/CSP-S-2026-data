#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    string c,z;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a>>c;
        for (int j=1;j<=a;j++)
        {
            z+=c;
        }
    }
    cout<<z;
    return 0;
}
