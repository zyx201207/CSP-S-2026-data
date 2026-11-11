#include <bits/stdc++.h>
using namespace std;
long long n,z,a[20000005];
string b,c;
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        for(int i=0;i<=a[i];i++)
        {
            c+=b;
        }
    }
    long long d=c.size()-1;
    for(int i=0;i<c.size()/2;i++)
    {
        if(c[i]=c[1])
        {
            c[1]=c[i];
            z++;
        }
    }
    cout << z;
    return 0;
}
