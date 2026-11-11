#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    for(int i=1;i<=b;i++)
    {
        cout<<(a+c+d+e+i-1)%3<<endl;
    }
}

